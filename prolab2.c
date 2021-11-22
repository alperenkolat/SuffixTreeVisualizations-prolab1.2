//Beyhan KARADAĞ 190201012 Alperen KOLAT 200201006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#define size 15
typedef struct branch
{
    char suffix[100];
    struct branch *next[size];
} branch;

typedef struct
{
    branch *next[10];
} root;

int node_counting(branch *p_branch, int *node_count);

branch *node_counting_caller(branch *p_branch,branch *adres[]);

int longest_find(branch *p_branch, char *longest, char *anlik);

branch *substring_check(branch *p_branch, char *aranan,branch *adres[]);

void tree_control(char *array);

void find_branch(char *suffix, branch *branch);

void string_scroll(char *str, int scr_value);

int compare_suffix(char *suffix, branch *p_branch);

int regulation_tree(branch *p_branch, char *suffix, int index, int scrool);

void home_screen(branch *root, branch *address[],branch *adres[]);

void CameraUpdate(float *CameraPosition, float x, float y,int width,int height);

void must_init(bool test, const char *description);

void show_root(branch *p_branch,double current_x,double current_y,int r, ALLEGRO_FONT* font,int distance,branch *adress[]);

void show_tree(branch *p_branch,double current_x,double current_y,int r,int i2,ALLEGRO_FONT* font,int distance,branch *adress[]);



int main()
{
    branch *root = malloc(sizeof(branch));
    char array[30];
    FILE *file = fopen("string.txt","r");
    fscanf(file,"%s",array);
    tree_control(array);

    for (int i = 0; i < strlen(array); i++) // Kelime parçalanarak ekleyici fonksiyona gönderiliyor
    {
        find_branch((array + i), root);
    }
    branch *address[4] = {NULL,NULL,NULL,NULL};
    branch *adres[10] = {NULL};


    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY* disp = al_create_display(1920, 1080);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");
    //ALLEGRO_BITMAP* mysha = al_load_bitmap("mysha2.jpg");
    //must_init(mysha, "mysha");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    float x, y;
    x = 100;
    y = 100;

    float CamPos[2] = {0,0};

    ALLEGRO_TRANSFORM Camera;

    al_start_timer(timer);


    #define KEY_SEEN     1
    #define KEY_RELEASED 2

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));

    double current_x = 4000;
    double current_y = 4000;
    int r = 45;
    double scaleX,scaleY;


    /* Mouse zoom kısmı
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_scale_transform(&t, scaleX, scaleY);
    al_use_transform(&t);*/
    int q=0;
    must_init(al_init_primitives_addon(), "primitives");
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                if(key[ALLEGRO_KEY_UP])
                    y -= 50;
                if(key[ALLEGRO_KEY_DOWN])
                    y+= 50;
                if(key[ALLEGRO_KEY_LEFT])
                    x-=50;  
                if(key[ALLEGRO_KEY_RIGHT])
                    x+= 50;
                if(key[ALLEGRO_KEY_A])
                    scaleX-= 0.01;
                if(key[ALLEGRO_KEY_D])
                    scaleX += 0.01;
                if(key[ALLEGRO_KEY_W])
                    scaleY -= 0.01;
                if(key[ALLEGRO_KEY_S])
                    scaleY += 0.01;
                else if(key[ALLEGRO_KEY_Q])
                    home_screen(root, address,adres);
                

                if(key[ALLEGRO_KEY_ESCAPE])
                    done = true;

                for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= KEY_SEEN;

                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= KEY_RELEASED;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), current_x-r, current_y, 0, "Root");
            al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
            al_draw_filled_rectangle(x, y, x + 10, y + 10, al_map_rgb(255, 0, 0));
            
            show_root(root,current_x,current_y,r,font,700,adres);

            
            CameraUpdate(CamPos,x,y,32,32);
            al_identity_transform(&Camera);
            al_translate_transform(&Camera,-CamPos[0],-CamPos[1]);
            al_scale_transform(&Camera,scaleX,scaleY);
            al_use_transform(&Camera);

            al_flip_display();

            redraw = false;
        }
    }

    
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    

    return 0;
}

branch *node_counting_caller(branch *p_branch,branch *adres[]) //en cok tekrar edebilecek dallari fonksiyona gönderir ve kıyaslar en büyügü bulur
{
    branch *most_repeat_p = NULL;
    int count = 0;             //gecici dal sayisini tutar
    int most_node[20];         //dal sayilarini tutar
    int most_repeat = 0;       //en cok tekrar edeni tutar
    int most_repeat_index = 0; //en cok tekrar edenin indisini tutar
    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i] != NULL) //dal var mı bakar
        {
            node_counting(p_branch->next[i], &count); //dal sayan fonsiyonu cagirir
            most_node[i] = count;
            count = 0;
            if (most_node[i] != 0)
                printf("%s katari %d kez tekrar ediyor\n", p_branch->next[i]->suffix, most_node[i]); //tekrar edenleri basawr

            if (most_node[i] > most_repeat) //en cok tekrar edeni bulur
            {
                most_repeat = most_node[i];
                most_repeat_index = i;
                most_repeat_p = p_branch->next[i];
            }
        }
    }
    if (most_repeat == 0)
    {
        printf("tekrarlanan katar yok\n");
    }
    else
    {
        printf("\n%s katari en çok tekrar eden katar %d kez tekrar ediyor\n", p_branch->next[most_repeat_index]->suffix, most_repeat);
    }

    for(int j=0;j<10;j++)
    {
        if(adres[j] == NULL)
         {
            adres[j] = most_repeat_p;
            break;
        }   
    }
    return most_repeat_p;
}

int node_counting(branch *p_branch, int *node_count) //dallari sayar
{
    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i] != NULL) //dal var mı bakar
        {
            if (p_branch->next[i]->next[0] == NULL) //dal yaprak ise sayar
            {

                (*node_count)++;
            }
            else //degilse alt daya geçer
            {

                node_counting(p_branch->next[i], node_count);
            }
        }
    }
    return 1;
}

void tree_control(char *array) //suffix tree control
{

    char suffix_1[100]; //suffix katari tutar
    char prefix_1[100]; //prefix katari tutar

    for (int i = 0; i < strlen(array) - 1; i++)
    {
        for (int j = 1; j < strlen(array); j++)
        {
            strncpy(suffix_1, array + strlen(array) - 1 - i, strlen(array)); // suffix olusturur
            strncpy(prefix_1, array, j);                                     //prefix  olusturur
                                                                             /*printf("%s-vs-", suffix_1);
            printf("%s\n", prefix_1);*/
            if (strcmp(suffix_1, prefix_1) == 0)                             //prefix ile suffix karsilaştirir
            {

                printf("\n suffix agaci olusturalamaz\n"); //!
            }
        }
        memset(prefix_1, 0, sizeof(prefix_1)); //sifirlaniyor tekrar tekrar karsilastirabilmek icin
    }
}

int longest_find(branch *p_branch, char *longest, char *anlik)
{

    char new_anlik[100];

    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i] != NULL) //dal yoksa bakılmaz
        {
            strcpy(new_anlik, anlik); //islem yapma icin atıyoruz
            strcat(new_anlik, p_branch->next[i]->suffix);
            if (p_branch->next[i]->next[0] == NULL) //dügüm yaprak ise tekrarlamıyor demektir
            {
                continue;
            }

            if (strlen(new_anlik) > strlen(longest)) //longest'dan uzun ise longesta atanir
            {
                strcpy(longest, new_anlik);
            }
            if (p_branch->next[i]->next[0] != NULL) //eger at dalı varsa altdayala gecilir
            {

                strcpy(anlik, new_anlik); //altadala geçmeden önce bu dalın katarı altdalda kullanmılmak
                return longest_find(p_branch->next[i], longest, anlik);
            }
        }
    }
    return 1;
}

branch *substring_check(branch *p_branch, char *arr,branch *adres[]) //aranan katar ağaçta var mı bakılır
{
    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i] != NULL)
        {

            if (arr[0] != p_branch->next[i]->suffix[0]) //eşleşme yoksa
            {
                continue;
            }
            if (arr[0] == p_branch->next[i]->suffix[0]) //tam eşleme varsa
            {
                for (int k = 0; k < strlen(arr); k++)
                {
                    if (p_branch->next[i]->suffix[k] == arr[k]) //sonek katarını ve aranan katarı char boyutunda karşılaştırıyor
                    {
                        if (strlen(arr) == k + 1) //eğer eşleşme tam ise bulundu diye bastırılır//uyarı hata verebilir nokta "for dongüsü sonek dizisi"
                        {
                            for(int j=0;j<10;j++)
                            {
                                if(adres[j] == NULL)
                                {
                                    adres[j] = p_branch->next[i];
                                    break;
                                }
                                
                            }
                            return p_branch->next[i];
                        }
                    }
                }
            }
            if (arr[0] == p_branch->next[i]->suffix[0]) //kismi eslesme varsa
            {
                int a = 0;

                while (arr[a] == p_branch->next[i]->suffix[a]) //benzer kisimlari sayar
                {

                    a++;
                }
                for (int j = 0; j < a; j++)
                {
                    for (int k = 0; k < strlen(arr); k++) //benzer kisimlari atar
                    {
                        arr[k] = arr[k + 1];
                    }
                }
                if (a == strlen(p_branch->next[i]->suffix)) // dalda uyusma var ise
                {
                    for(int j=0;j<10;j++)
                    {
                        if(adres[j] == NULL)
                        {
                           adres[j] = p_branch->next[i]; 
                           break;
                        } 
                        
                    }
                    return substring_check(p_branch->next[i], arr,adres); //alt dala geser
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
    return NULL; //eşleşme yoksa
}

void find_branch(char *suffix, branch *p_branch)
{
    int str_index = 0;
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i] != NULL) // Kökte ekli olanlar ile benzerlik aranıyor
        {
            str_index = compare_suffix(suffix, p_branch->next[i]); // Metinler kıyaslanıyor ve ilk kaç hanesinin benzer olduğu saptanıyor

            if (str_index != 0)
            {
                flag = regulation_tree(p_branch, suffix, i, str_index); //Benzer hane varsa düzenleme fonksiyonu başlatılıyor
            }
        }
    }

    if (flag == 0) // 0 İse düzenleme fonksiyonu çalışmamış demektir str index almadık çünkü o hepsini kontrol ediyor ve en sonda 0 döndürebilir
    {
        for (int i = 0; i < size; i++)
        {
            if (p_branch->next[i] == NULL) // Köke yeni dalı ekliyoruz
            {
                p_branch->next[i] = malloc(sizeof(branch));
                strcpy(p_branch->next[i]->suffix, suffix);
                break;
            }
        }
    }
}

int compare_suffix(char *suffix, branch *p_branch) //Yakınlık kıyaslayıcı ancak şu an daha genellenemdi her senaryoda çalışamaz
{
    for (int i = 0; *(suffix + i) != '\0'; i++)
    {
        if (*(suffix + i) != p_branch->suffix[i])
        {
            return i;
        }
    }
    return 0;
}

int regulation_tree(branch *p_branch, char *suffix, int index, int scrool) // Düzenleme Fonksiyonu
{
    char new_suffix[100];
    strcpy(new_suffix, suffix);
    string_scroll(new_suffix, scrool);

    int new = 0;

    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[index]->next[i] != NULL)
        {
            new = compare_suffix(new_suffix, p_branch->next[index]->next[i]);
            if (new != 0)
            {
                regulation_tree(p_branch->next[index], new_suffix, i, new);
                return 1;
            }
        }
    }

    int flag2 = 0;
    if (strlen(p_branch->next[index]->suffix) == scrool)
    {
        for (int i = 0; i < size; i++)
        {
            if (p_branch->next[index]->next[i] == NULL) // Köke yeni dalı ekliyoruz
            {
                p_branch->next[index]->next[i] = malloc(sizeof(branch));
                strcpy(p_branch->next[index]->next[i]->suffix, new_suffix);
                flag2 = 1;
                return 1;
            }
        }
    }

    branch *new_branch = malloc(sizeof(branch));  // Araya girecek düğüm
    branch *new_branch2 = malloc(sizeof(branch)); //Dallanacak düğüm

    for (int i = 0; i < scrool; i++)
        new_branch->suffix[i] = *(suffix + i); // Araya girecek düğümün suffix texti oluşturuluyor

    new_branch->next[0] = p_branch->next[index]; // Eski düğüm araya girecek düğüm tarafından işaret ettiriliyor
    new_branch->next[1] = new_branch2;           // Dallanacak yeni düğüm araya girecek düğüm tarafından işaret ettiriliyor

    string_scroll(p_branch->next[index]->suffix, scrool); // Eski düğümün texti düzenleniyor kesişime kadar olan bölge atılıyor

    strcpy(new_branch2->suffix, suffix);        // Yeni dalın isminin HEPSİ yazılıyor
    string_scroll(new_branch2->suffix, scrool); // Araya girecek düğümün sahip olduğu kısımlar textten kaydırılıyor 2 satır yukarıdaki gibi

    p_branch->next[index] = new_branch; // Kökteki adres araya giren düğüme işaret ettiriliyor böylece araya girme işlemi tamamlanmış oluyor
    return 1;
}

void string_scroll(char *str, int scr_value) // Texti düzenleyen fonksiyon
{
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++)
    {
        *(str + i) = *(str + scr_value + i);
    }
}

void home_screen(branch *root, branch *address[],branch *adres[])
{
    int repaet_count = 0;
    int secim;
    char longest[10];
    char longest_copy[10];
    char anlik_long[10];
    char aranan[10];
    char aranan_copy[10];

    printf("%s\n\t* * * * * * * * * MENU * * * * * * * * *\n\n", "\x1B[0m");
    printf("\tKatari icinde p katari geciyor mu ?; \n\t Geciyorsa gectigi ilk pozisyon yeri\n\t Ve kac kez tekrar ettigini  \n\t\t\t gormek icin 1\'ye basiniz...\n\n");
    printf("\tKatari icin  en uzun tekrar eden altkatari bulmak; \n\t Ve kac kez tekrar ettigini \n\t\t\tGormek icin 2\'e basiniz...\n\n");
    printf("\tKatari icin en cok tekrar eden alt katari bulmak ;\n\t Ve kez tekrar ettigini \n\t\t\tGormek icin 3\'e basiniz..\n\n");
    printf("\tProgramdan cikmak icin 0\'a basiniz...\n\n");
    printf("Secim giriniz:\n");
    scanf("%d", &secim);
    if(secim == 1)
    {
        printf("aranan katari girin..\n");
        scanf("%s", aranan);
        strcpy(aranan_copy, aranan);
        memset(adres, NULL, sizeof(adres)*10);
        address[2] = substring_check(root, aranan,adres);
        if (address[2] != NULL)
        {
            node_counting(address[2], &repaet_count);
            printf("bulundu ..aranan katar  %s tekrar sayisi %d ..\n", aranan_copy, repaet_count);
        }
        else
        {
            printf("bulunamadi..\n");
        }
        repaet_count = 0;

    }
    if(secim == 2)
    {

        
        memset(anlik_long, 0, sizeof(anlik_long));
        longest_find(root, longest, anlik_long);
        printf("-%s-\n", longest); //ek
        strcpy(longest_copy, longest);
        memset(adres, NULL, sizeof(adres)*10);
        address[1] = substring_check(root, longest,adres);
        node_counting(address[1], &repaet_count);
        printf("en uzun katar  %s tekrar sayisi %d..\n", longest_copy, repaet_count);
        repaet_count = 0;
            
    }
    if(secim == 3)
    {
        memset(adres, NULL, sizeof(adres)*10);
        address[0] = node_counting_caller(root,adres);
    }
    
}

void CameraUpdate(float *CameraPosition, float x, float y,int width,int height)
{
    CameraPosition[0] = - (1920/2) + (x + width/2);
    CameraPosition[1] = -(1080/2) + (y + height)/2;

    if (CameraPosition[0] < 0 ) CameraPosition[0] = 0;
    if (CameraPosition[1] < 0 ) CameraPosition[1] = 0;

}

void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void show_root(branch *p_branch,double current_x,double current_y,int r, ALLEGRO_FONT* font,int distance,branch *adress[])
{   
    double val = 3.14159265/180;
    int j=0;
    for(;p_branch->next[j] != NULL;j++);
    if(j == 0) return 0;
    int new_line = 120/(j-1);
    int branch_size = 0;
    int color = 0;
    al_draw_circle(current_x , current_y , r, al_map_rgb_f(1, 0, 1), 2);





    for(int i=0 ,i2 = -60;i<=120 && branch_size <j;i = i + new_line, i2 = i2+30,branch_size++)
    {

        for(int i=0;i<10;i++)
        {
            if(p_branch->next[branch_size] == adress[i])
            {
                color = 1;
                break;
            }
            else color = 0;
        }

        al_draw_line(current_x + -1*(cos((val)*(i+30))*r), current_y + (sin((val)*(i+30))*r), current_x + -1*(cos((val)*(i+30))*distance), current_y + (sin((val)*(i+30))*distance) , al_map_rgb_f(1, color, 0), 1); // Çizgi çizer
        al_draw_circle(current_x + -1*(cos((val)*(i+30))*distance) + -1*(cos((val)*(i+30))*r) , current_y + (sin((val)*(i+30))*distance) + (sin((val)*(i+30))*r), r, al_map_rgb_f(1, color, 1), 2);
        al_draw_text(font, al_map_rgb(255, 255, 255),current_x + -1*(cos((val)*(i+30))*distance) + -1*(cos((val)*(i+30))*r) -r +1 , current_y + (sin((val)*(i+30))*distance) + (sin((val)*(i+30))*r), 0, p_branch->next[branch_size]->suffix);// Son kısımları yazmayacak


        show_tree(p_branch->next[branch_size],current_x + -1*(cos((val)*(i+30))*distance) + -1*(cos((val)*(i+30))*r) ,current_y + (sin((val)*(i+30))*distance) + (sin((val)*(i+30))*r) ,r,i2,font,distance,adress);
    }

}

void show_tree(branch *p_branch,double current_x,double current_y,int r,int i2,ALLEGRO_FONT* font,int distance,branch *adress[])
{   
    double val = 3.14159265/180;
    int j=0;
    for(;p_branch->next[j] != NULL;j++);
    if(j ==0) return 0;
    float new_line = 120/(j+2);
    int branch_size = 0;
    int color = 0;


    for(int i=120 ;i>0 && branch_size <j ;i = i - new_line,branch_size++)
    {
        for(int i=0;i<10;i++)
        {
            if(p_branch->next[branch_size] == adress[i])
            {
                color = 1;
                break;
            }
            else color = 0;
        }

        al_draw_line(current_x + -1*(cos((val)*(i+30+i2))*r), current_y + (sin((val)*(i+30+i2))*r), current_x + -1*(cos((val)*(i+30+i2))*distance), current_y + (sin((val)*(i+30+i2))*distance) , al_map_rgb_f(1, color, 0), 1); // Çizgi çizer
        al_draw_circle(current_x + -1*(cos((val)*(i+30+i2))*distance) + -1*(cos((val)*(i+30))*r) , current_y + (sin((val)*(i+30+i2))*distance) + (sin((val)*(i+30))*r), r, al_map_rgb_f(1, color, 1), 2);
        al_draw_text(font, al_map_rgb(255, 255, 255), current_x + -1*(cos((val)*(i+30+i2))*distance) + -1*(cos((val)*(i+30))*r) -r, current_y + (sin((val)*(i+30+i2))*distance) + (sin((val)*(i+30))*r), 0, p_branch->next[branch_size]->suffix);// Son kısımları yazmayacak
        show_tree(p_branch->next[branch_size],current_x + -1*(cos((val)*(i+30+i2))*distance) + -1*(cos((val)*(i+30))*r),current_y + (sin((val)*(i+30+i2))*distance) + (sin((val)*(i+30))*r),r,i2,font,distance,adress);

    }
}
