//Beyhan KARADAĞ 190201012 Alperen KOLAT 200201006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 15
typedef struct branch
{
    char suffix[100];
    struct branch *next[size];
}branch;

typedef struct
{
    branch *next[10];
}root;

int node_counting(branch *p_branch,int *node_count);
int node_counting_caller(branch *p_branch);


int longest_find(branch *p_branch, char *longest, char *anlik);
int substring_check(branch *p_branch, char *aranan);
void tree_control(char *array);

void find_branch(char *suffix,branch *branch);

void string_scroll(char *str,int scr_value);

int compare_suffix(char *suffix, branch *p_branch);

int regulation_tree(branch *p_branch,char *suffix,int index, int scrool);

int main()
{
    branch  *root = malloc(sizeof(branch));
    char array[30] = "abcpqrabpqpqab$";
    tree_control(array);
    for(int i =0;i<strlen(array);i++)// Kelime parçalanarak ekleyici fonksiyona gönderiliyor
    {
        find_branch((array+i),root);
    }


    node_counting_caller(root);


    printf("a\n");
    char longest[100];//ek
    char anlik_long[100];
    longest_find(root, longest, anlik_long);
    printf("%s\n", longest);//ek


    /* char aranan[100];
    printf("aranan katari girin..\n");
    scanf("%s",aranan);
    int z=substring_check(root,aranan);
    printf("%d",z);*/


    return 0;
}
int node_counting_caller(branch *p_branch)//en cok tekrar edebilecek dallari fonksiyona gönderir ve kıyaslar en büyügü bulur
{    branch *most_repeat_p;
    int count = 0;//gecici dal sayisini tutar
    int most_node[20];//dal sayilarini tutar
    int most_repeat = 0;//en cok tekrar edeni tutar
    int most_repeat_index = 0;//en cok tekrar edenin indisini tutar
    for (int i = 0; i < size; i++)
    {  if (p_branch->next[i] != NULL)//dal var mı bakar
        {
        node_counting(p_branch->next[i], &count);//dal sayan fonsiyonu cagirir
        most_node[i] = count;
        count = 0;
        if (most_node[i]!=0)
        printf("%s katari %d kez tekrar ediyor\n", p_branch->next[i]->suffix, most_node[i]);//tekrar edenleri basawr

        if (most_node[i] > most_repeat)//en cok tekrar edeni bulur
        {
            most_repeat = most_node[i];
            most_repeat_index = i;
           most_repeat_p=p_branch->next[i];
        }
     }

    }
    if (most_repeat == 0)
    {
        printf("tekrarlanan katar yok");
    }
    else
    {
        printf("\n%s katari en çok tekrar eden katar %d kez tekrar ediyor\n", p_branch->next[most_repeat_index]->suffix, most_repeat);
    }
    return 1;// most_repeat_p;
}

int node_counting(branch *p_branch, int *node_count)//dallari sayar
{
    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i] != NULL)//dal var mı bakar
        {
            if (p_branch->next[i]->next[0] == NULL)//dal yaprak ise sayar
            {

                (*node_count)++;
            }
            else//degilse alt daya geçer
            {

                return node_counting(p_branch->next[i], node_count);
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

                printf("\n suffix agaci olusturalamaz\n");//!
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
        strcpy(new_anlik, anlik);//islem yapma icin atıyoruz
        if (p_branch->next[i] != NULL)//dal yoksa bakılmaz
        {
            strcat(new_anlik, p_branch->next[i]->suffix);
            if (p_branch->next[i]->next[0] == NULL)//dügüm yaprak ise tekrarlamıyor demektir
            {
                continue;
            }

            if (strlen(new_anlik) > strlen(longest)) //longest'dan uzun ise longesta atanir
            {
                strcpy(longest, new_anlik);
            }
            if (p_branch->next[i]->next[0] != NULL) //eger at dalı varsa altdayala gecilir
            {

                strcpy(anlik, new_anlik);//altadala geçmeden önce bu dalın katarı altdalda kullanmılmak
                return longest_find(p_branch->next[i], longest, anlik);
            }
        }
    }
    return 1;
}

int substring_check(branch *p_branch, char *arr) //aranan katar ağaçta var mı bakılır
{
    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[i]!=NULL){

        if (arr[0] != p_branch->next[i]->suffix[0]) //eşleşme yoksa
        {
            continue;
        }
        if (arr[0] == p_branch->next[i]->suffix[0]) //tam eşleme varsa  (aranan[]==p_branch->next[i]->suffix[])
        {
            for (int k = 0; k < strlen(arr); k++)
            {
                if (p_branch->next[i]->suffix[k] == arr[k]) //sonek katarını ve aranan katarı char boyutunda karşılaştırıyor
                {
                    if (strlen(arr) == k + 1) //eğer eşleşme tam ise bulundu diye bastırılır//uyarı hata verebilir nokta "for dongüsü sonek dizisi"
                    {
                        printf("var %d\n", i);
                        return 1;//p_branch->next[i];
                    }
                }
            }
        }
        if (arr[0] == p_branch->next[i]->suffix[0]) //kısmi eşlesme varsa
        {  int a=0;

            while (arr[a] == p_branch->next[i]->suffix[a]) //benzer kısımları sayar
            {

                a++;
            }
            for (int j=0; j<a;j++){
               for (int k = 0; k <strlen(arr); k++)//benzer kısımları atar
                {
                    arr[k] = arr[k + 1];

                }
            }

            return substring_check(p_branch->next[i], arr);//alt dala geçer
        }
    }
}
    return -1; //eşleşme yoksa
}
void find_branch(char *suffix,branch *p_branch)
{
    int str_index = 0;
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(p_branch->next[i] != NULL) // Kökte ekli olanlar ile benzerlik aranıyor
        {
            str_index = compare_suffix(suffix,p_branch->next[i]);// Metinler kıyaslanıyor ve ilk kaç hanesinin benzer olduğu saptanıyor

            if(str_index != 0)
            {
                flag = regulation_tree(p_branch,suffix,i,str_index);//Benzer hane varsa düzenleme fonksiyonu başlatılıyor

            }
        }

    }

    if(flag == 0) // 0 İse düzenleme fonksiyonu çalışmamış demektir str index almadık çünkü o hepsini kontrol ediyor ve en sonda 0 döndürebilir
    {
        for(int i=0;i<size;i++)
        {
            if(p_branch->next[i] == NULL) // Köke yeni dalı ekliyoruz
            {
                p_branch->next[i] = malloc(sizeof(branch));
                strcpy(p_branch->next[i]->suffix,suffix);
                break;
            }

        }
    }

}

int compare_suffix(char *suffix, branch *p_branch) //Yakınlık kıyaslayıcı ancak şu an daha genellenemdi her senaryoda çalışamaz
{
    for(int i=0;*(suffix+i) != '\0';i++)
    {
        if( *(suffix+i) != p_branch->suffix[i])
        {
            return i;
        }
    }
    return 0;
}

int regulation_tree(branch *p_branch,char *suffix,int index, int scrool) // Düzenleme Fonksiyonu
{
    char new_suffix[100];
    strcpy(new_suffix,suffix);
    string_scroll(new_suffix,scrool);

    int new = 0;

    for(int i=0;i<size;i++)
    {
        if(p_branch->next[index]->next[i] != NULL)
        {
            new = compare_suffix(new_suffix,p_branch->next[index]->next[i]);
            if(new != 0)
            {
                regulation_tree(p_branch->next[index],new_suffix,i,new);
                return 1;
            }
        }
    }

    int flag2=0;
    if(strlen(p_branch->next[index]->suffix) == scrool)
    {
        for(int i=0;i<size;i++)
        {
            if(p_branch->next[index]->next[i] == NULL) // Köke yeni dalı ekliyoruz
            {
                p_branch->next[index]->next[i] = malloc(sizeof(branch));
                strcpy(p_branch->next[index]->next[i]->suffix,new_suffix);
                flag2 =1;
                return 1;
            }

        }
    }



    branch *new_branch = malloc(sizeof(branch));// Araya girecek düğüm
    branch *new_branch2 = malloc(sizeof(branch));//Dallanacak düğüm

    for(int i=0; i<scrool; i++) new_branch->suffix[i] = *(suffix+i); // Araya girecek düğümün suffix texti oluşturuluyor

    new_branch->next[0] = p_branch->next[index]; // Eski düğüm araya girecek düğüm tarafından işaret ettiriliyor
    new_branch->next[1] = new_branch2; // Dallanacak yeni düğüm araya girecek düğüm tarafından işaret ettiriliyor


    string_scroll(p_branch->next[index]->suffix,scrool); // Eski düğümün texti düzenleniyor kesişime kadar olan bölge atılıyor

    strcpy(new_branch2->suffix,suffix);// Yeni dalın isminin HEPSİ yazılıyor
    string_scroll(new_branch2->suffix,scrool); // Araya girecek düğümün sahip olduğu kısımlar textten kaydırılıyor 2 satır yukarıdaki gibi

    p_branch->next[index] = new_branch; // Kökteki adres araya giren düğüme işaret ettiriliyor böylece araya girme işlemi tamamlanmış oluyor
    return 1;

}

void string_scroll(char *str,int scr_value)// Texti düzenleyen fonksiyon
{
    int str_len = strlen(str);
    for(int i=0;i<str_len;i++)
    {
        *(str+i) = *(str+scr_value+i);
    }
}


int home_screen()
{

    int secim;


    while (1)
    {
        printf("%s\n\t* * * * * * * * * MENU * * * * * * * * *\n\n", "\x1B[0m");
        printf("\tKatari icin sonek agaci olusturabilir mi ? \n\t\t\tGormek icin 1\'e basiniz ...\n\n");
        printf("\tKatari icinde p katari geciyor mu ?; \n\t Geciyorsa gectigi ilk pozisyon yeri\n\t Ve kac kez tekrar ettigini  \n\t\t\t gormek icin 2\'ye basiniz...\n\n");
        printf("\tKatari icin  en uzun tekrar eden altkatari bulmak; \n\t Ve kac kez tekrar ettigini \n\t\t\tGormek icin 3\'e basiniz...\n\n");
        printf("\tKatari icin en cok tekrar eden alt katari bulmak ;\n\t Ve kez tekrar ettigini \n\t\t\tGormek icin 4\'e basiniz..\n\n");
        printf("\tProgramdan cikmak icin 0\'a basiniz...\n\n");
        printf("Secim giriniz:\n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:


            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;

        case 0:
            printf("%s\n\tPROGRAMDAN CIKIS YAPTINIZ...\n", "\x1B[33m");
            exit(0);
            break;

        default:
            printf("böyle bir secim yok...");
            break;
        }
    }

    return 0;
}
