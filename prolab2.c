//Beyhan KARADAĞ 190201012 Alperen KOLAT 200201006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 2500

typedef struct branch
{
    char suffix[10000];
    struct branch *next[size];
} branch;

typedef struct
{
    branch *next[10000];
} root;
int dal_sayisi = 0;
branch *adres;
int dal_sayan(branch *p_branch,int *flag3);
int konumlandir(branch *p_branch,int *flag3);
void caller(branch *p_branch);

int suffixtreecontrol();

void find_branch(char *suffix, branch *branch);

void string_scroll(char *str, int scr_value);

<<<<<<< HEAD
int compare_suffix(char *suffix, branch *p_branch);
=======
int suffixtreecontrol();
>>>>>>> 9294409d72359968c2959b96fae04e34dd2eb659

int regulation_tree(branch *p_branch, char *suffix, int index, int scrool);

<<<<<<< HEAD
int main()
{
    branch *root = malloc(sizeof(branch));
    char array[18000] = "attaaaggtttataccttcccaggtaacaaaccaaccaactttcgatctcttgtagatctgttctctaaacgaactttaaaatctgtgtggctgtcactcggctgcatgcttagtgcactcacgcagtataattaataactaattactgtcgttgacaggacacgagtaactcgtctatc$";
    for (int i = 0; i < strlen(array); i++) // Kelime parçalanarak ekleyici fonksiyona gönderiliyor
=======
void find_branch(char *suffix,branch *branch);
>>>>>>> 9294409d72359968c2959b96fae04e34dd2eb659

    {
        find_branch((array + i), root);

    }
    printf("\na\n");

    //  printf("\n %s",root->next[4]->suffix);
    caller(root);
    printf("\na\n");

    return 0;
}
int liste[30]; //yigin
int a = -1;
int g=0;

int indis = 0;

void caller(branch *p_branch_as)
{
<<<<<<< HEAD

    int en_cok_dal_index = 0;
    int en_cok_dal = 0;
    int flag3 = 0;
    int dizi[size];
    for (int i = 0; p_branch_as->next[i] != NULL; i++)
    {  liste[0]=-1;
         adres =p_branch_as->next[i];
        dizi[i] = dal_sayan(p_branch_as->next[i], &flag3);
        printf("qq%d\n",dizi[i]);
        if (dizi[i] > en_cok_dal)
        {
            en_cok_dal = dizi[i];
            en_cok_dal_index = i;
        }
        g=0;
         a = -1;
        dal_sayisi = 0;
        flag3 = 0;
    }
    if (en_cok_dal == 0)
    {
        printf("tekrarlanan katar yok");
    }
    else
=======
    branch  *root = malloc(sizeof(branch));
    char array[30] = "attaaagg$";
    for(int i =0;i<strlen(array);i++)// Kelime parçalanarak ekleyici fonksiyona gönderiliyor
>>>>>>> 9294409d72359968c2959b96fae04e34dd2eb659
    {
        printf("\n%s katari en çok tekrar eden katar %d kez tekrar ediyor\n", p_branch_as->next[en_cok_dal_index]->suffix, en_cok_dal);
    }
}
int c =0;

int konumlandir(branch *p_branch,  int *flag3)
{
    a++;
    if ((a != *(flag3)-1) && (*flag3 >= 2)) //true-2 mi
    {
       konumlandir(p_branch->next[liste[a]], flag3);
       return dal_sayisi;

    }

    //if(g==0){
       c=1;
      a=-1;
     return dal_sayan(p_branch,  flag3);
    //}
    //else{
     //return dal_sayisi;
 // }
}
int dal_sayan(branch *p_branch,  int *flag3)
   {int b;
     if (c==1)
    {
         b = (liste[*(flag3)-1]) + 1;
         (*flag3)--;
        liste[*flag3] = -1;
    }
    else
    {
        b = 0;
    }
    for (int i = b; p_branch->next[i] != NULL; i++)
    {
        if (p_branch->next[i]->next[0] == NULL)
        {

            dal_sayisi++;
        }
        else
        {

            liste[*flag3] = i;
            liste[*(flag3) + 1] = -1;
            (*flag3)++;
            c=0;
            int m=dal_sayan(p_branch->next[i],flag3);
            return dal_sayisi;//?


        }
    }
    //if(flag3!=0){
    if (liste[0] == -1)
    { c=0;
    g=1;
        return dal_sayisi;


    }
    else
    {
       // (*flag3)--;
        //liste[*flag3] = -1;
        konumlandir(adres,flag3);
        return dal_sayisi;//?

    }
}

int suffixtreecontrol()
{
    char str[4000];
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

    for (int i = 0; i < 1; i++) //düzenlenebilir
    {
        if (str[i] == str[str_lentgh + i - 2])
        {
            if (str[i + 1] == str[str_lentgh + i - 1])
            {
                sonuc = 1;
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

    return 1;
}

int regulation_tree(branch *p_branch, char *suffix, int index, int scrool) // Düzenleme Fonksiyonu
{
    char new_suffix[10000];
    strcpy(new_suffix, suffix);
    string_scroll(new_suffix, scrool);

    int new = 0;

    for (int i = 0; i < size; i++)
    {
        if (p_branch->next[index]->next[i] != NULL)
        {
<<<<<<< HEAD
            new = compare_suffix(new_suffix, p_branch->next[index]->next[i]);
            if (new != 0)
=======
            new = compare_suffix(new_suffix,p_branch->next[index]->next[i]);
            if(new != 0)
>>>>>>> 9294409d72359968c2959b96fae04e34dd2eb659
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