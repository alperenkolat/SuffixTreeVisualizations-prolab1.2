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

int main()
{
    branch *root = malloc(sizeof(branch));
    char array[10] = "xabxac";
    find_branch(array,root);

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

void find_branch(char *suffix,branch *branch)
{
    int str_index = 0;
    int flag=0;
    for(int i=0;i<5;i++)
    {
        if(branch->next[i] != NULL)
        {
            str_index = compare_suffix(suffix,branch->next[i]);

            if(str_index != 0)
            {
                flag = regulation_tree(branch->next[i],suffix);
                
            }
        }

    }

    if(flag == 0)
    {
        regulation_tree(branch,suffix);
    }
}

int compare_suffix(char *suffix, branch *branch)
{
    for(int i=0;*(suffix+i) != '\0';i++)
    {
        if( *(suffix+i) != branch->suffix[i])
        {
            return i;
        }
    }
}

int regulation_tree(branch *branch,char *suffix)
{
    strcpy(branch->suffix,suffix);
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