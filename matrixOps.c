#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

void kontroller(int argc, char *satir, char *sutun, char *yon, char *maxdeger, char *adim)
{

    if (argc != 6)
    {
        printf("Arguman sayisi hatali.");
    }
    while (atoi(satir) <= 1 || atoi(satir) > 1000 || isdigit(*satir) == 0)
    {
        printf("Lutfen 1 - 1000 arasinda bir satir sayisi girin: ");
        scanf("%s", satir);
    }
    while (atoi(sutun) <= 1 || atoi(sutun) > 1000 || isdigit(*sutun) == 0)
    {
        printf("Lutfen 1 - 1000 arasinda bir sutun sayisi girin: ");
        scanf("%s", sutun);
    }
    while ((atoi(yon) != 1 && atoi(yon) != -1))
    {
        printf("Lutfen uygun bir yon girin: ");
        scanf("%s", yon);
    }
    if (atoi(maxdeger) < 0 || isdigit(*maxdeger) == 0)
    {
        printf("Lutfen uygun bir maksimum deger girin: ");
        scanf("%s", maxdeger);
    }
    while (atoi(adim) < 0 || isdigit(*adim) == 0)
    {
        printf("Lutfen uygun bir donme sayisi girin: ");
        scanf("%s", adim);
    }
}
void menu_kontrol(char input)
{

    while ((atoi(&input) < 1) || (atoi(&input)) > 5 || isdigit(input) == 0)
    {
        printf("Lutfen 0 ile 6 arasinda bir rakam girin\n"
               "MENU:\n"
               "1. Uygulamayi calistir\n"
               "2. Matris olustur\n"
               "3. Direction\n"
               "4. Step number\n"
               "5. Exit\n");
        printf("Yapmak istediginiz islem:");
        scanf("%s", &input);
    }
}
void yazdir(int **dizi, int satir, int sutun)
{
    printf("\n");
    for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j < sutun; j++)
        {
            printf("%d  ", *(*(dizi + i) + j));
        }
        printf("\n");
    }
}

int **matrisOlustur(int satir, int sutun, int maxdeger)
{

    int **dizi;
    srand(time(0));
    dizi = malloc(satir * sizeof(int *));

    for (int i = 0; i < satir; i++)
    {
        *(dizi + i) = malloc(sutun * sizeof(int));
    }

    for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j < sutun; j++)
        {
            *(*(dizi + i) + j) = rand() % maxdeger;
        }
    }

    return dizi;
}

void Dondur(int **dizi, int satir, int sutun, int yon, int adim)
{

    for (int i = 0; i < adim; i++)
    {

        if (yon == 1)
        {

            int temp = *(*(dizi + 1) + 0);
            int i = 0;
            int j = 0;
            int dongu = *(*(dizi + i) + j);

            for (; j < sutun; j++)
            {
                dongu = *(*(dizi + i) + j);
                *(*(dizi + i) + j) = temp;
                temp = dongu;
            }

            i++;
            j--;

            for (; i < satir; i++)
            {
                dongu = *(*(dizi + i) + j);
                *(*(dizi + i) + j) = temp;
                temp = dongu;
            }

            i--;
            j = sutun - 2;

            for (; j >= 0; j--)
            {
                dongu = *(*(dizi + i) + j);
                *(*(dizi + i) + j) = temp;
                temp = dongu;
            }

            j++;
            i = satir - 2;

            for (; i >= 0; i--)
            {
                dongu = *(*(dizi + i) + j);
                *(*(dizi + i) + j) = temp;
                temp = dongu;
            }
        }

        if (yon == -1)
        {

            int i = 0;
            int j = 0;
            int temp = *(*(dizi + 0) + 1);
            int ilk = *(*(dizi + 0) + 0);

            for (; j < sutun - 1; j++)
            {
                *(*(dizi + i) + j) = temp;
                temp = *(*(dizi + i) + j + 2);
            }

            for (; i < satir - 1; i++)
            {
                temp = *(*(dizi + i + 1) + j);
                *(*(dizi + i) + j) = temp;
            }

            for (; j > 0; j--)
            {
                temp = *(*(dizi + i) + j - 1);
                *(*(dizi + i) + j) = temp;
            }

            for (; i > 0; i--)
            {
                if (i > 0)
                {
                    temp = *(*(dizi + i - 1) + j);
                    *(*(dizi + i) + j) = temp;
                }
            }
            *(*(dizi + 1) + 0) = ilk;
        }
    }
}

void sil(int satir, int **dizi)
{
    // memoryde dizi icin ayrilan yeri serbest birakir
    for (int i = 0; i < satir; i++)
    {
        free(*(dizi + i));
    }
    free(dizi);
}
