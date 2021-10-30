//Beyhan KARADAĞ 190201012 Alperen KOLAT 200201006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct branch
{
    char suffix[100];
    struct branch *next[5];
}branch;

typedef struct
{
    branch *next[10];
}root;




void suffixtreecontrol();


void add_branch(char *suffix,branch *branch);

void string_scroll(char *str,int scr_value);

int compare_suffix(char *suffix, branch *p_branch);

int regulation_tree(branch *p_branch,char *suffix,int index, int scrool);

int main()
{
    branch  *root = malloc(sizeof(branch));
    char array[15] = "agtttatacct";
    for(int i =0;i<strlen(array);i++)// Kelime parçalanarak ekleyici fonksiyona gönderiliyor
    {
        find_branch((array+i),root);
    }
    

    return 0;
}

void suffixtreecontrol()
{
    char str[40];
    int str_lentgh = 0;
    int sonuc = 0;

    FILE *dosyaSTR;
    if ((dosyaSTR = fopen("string.txt", "r")) == NULL)
    {
        printf("dosya acma hatasi!\n");
        exit(1);
    }

    //Kullanıcıdan alınmalı
    fscanf(dosyaSTR, "%s", str);  
    str_lentgh = strlen(str);

    for (int i = 0; i <1; i++)//düzenlenebilir
    {
        if (str[i]==str[str_lentgh+i-2])
        {
            if (str[i+1]==str[str_lentgh+i-1])
            {
                sonuc=1;
            }
            
        }
        
    }
    
    if (sonuc == 1)
    {
        printf("%s\n %s katari icin sonek agaci olusturulamaz!\n\n", "\x1B[31m", str);
    }
    if (sonuc == 0)
    {

        printf("%s\n %s katari icin sonek agaci olusturulabilir!\n\n", "\x1B[34m", str);
    }
    fclose(dosyaSTR);

    return 0;
}

void find_branch(char *suffix,branch *p_branch)
{
    int str_index = 0;
    int flag=0;
    for(int i=0;i<5;i++)
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
        for(int i=0;i<5;i++)
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
}

int regulation_tree(branch *p_branch,char *suffix,int index, int scrool) // Düzenleme Fonksiyonu
{
    branch *new_branch = malloc(sizeof(branch));// Araya girecek düğüm
    branch *new_branch2 = malloc(sizeof(branch));//Dallanacak düğüm

    for(int i=0; i<scrool; i++) new_branch->suffix[i] = *(suffix+i); // Araya girecek düğümün suffix texti oluşturuluyor

    new_branch->next[0] = p_branch->next[index]; // Eski düğüm araya girecek düğüm tarafından işaret ettiriliyor
    new_branch->next[1] = new_branch2; // Dallanacak yeni düğüm araya girecek düğüm tarafından işaret ettiriliyor


    string_scroll(p_branch->next[index]->suffix,scrool); // Eski düğümün texti düzenleniyor kesişime kadar olan bölge atılıyor

    strcpy(new_branch2->suffix,suffix);// Yeni dalın isminin HEPSİ yazılıyor
    string_scroll(new_branch2->suffix,scrool); // Araya girecek düğümün sahip olduğu kısımlar textten kaydırılıyor 2 satır yukarıdaki gibi

    p_branch->next[index] = new_branch; // Kökteki adres araya giren düğüme işaret ettiriliyor böylece araya girme işlemi tamamlanmış oluyor

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

            suffixtreecontrol();
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