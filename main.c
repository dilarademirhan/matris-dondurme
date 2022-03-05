/*@file main.c
  @description Cok boyutlu (2D array) bir matrix icin,
  belirlenen yonde ve adet miktarinca matrix’in
  koselerinde bulunan elemanlarini donduren ve ekrana yazan
  uygulama
  @assignment 1. Odev
  @date 02.12.2019
  @author Dilara Demirhan dilara.demirhan@stu.fsm.edu.tr */


#include <stdio.h>
#include <stdlib.h>
#include "matrixOps.h"
#include <ctype.h>

int main(int argc, char *argv[]) {

    int calistir = 0;

    kontroller(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);

    int** dizi = matrisOlustur(atoi(argv[1]), atoi(argv[2]), atoi(argv[4]));
    yazdir(dizi, atoi(argv[1]), atoi(argv[2]));
    Dondur(dizi, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[5]));
    yazdir(dizi, atoi(argv[1]), atoi(argv[2]));


    while(1){
        printf("MENU:\n"
           "1. Uygulamayi calistir\n"
           "2. Matris olustur\n"
           "3. Yon\n"
           "4. Adim Sayisi\n"
           "5. Cikis\n");

        char input;
        printf("Yapmak istediginiz islem:");
        scanf("%s", &input);
        menu_kontrol(input);

        while(atoi(&input) > 0 && atoi(&input) < 6){

          if (atoi(&input) == 1){
              Dondur(dizi, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[5]));
              yazdir(dizi, atoi(argv[1]), atoi(argv[2]));
              break;
          }
          else if (atoi(&input) == 2){
              sil(atoi(argv[1]), dizi);
              printf("satir: ");
              scanf("%s", argv[1]);
              kontroller(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
              printf("sutun: ");
              scanf("%s", argv[2]);
              kontroller(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
              printf("Dizi elemanlarinin alabilecegi en buyuk deger: ");
              scanf("%s", argv[4]);
              kontroller(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
              dizi = matrisOlustur(atoi(argv[1]), atoi(argv[2]), atoi(argv[4]));
              yazdir(dizi, atoi(argv[1]), atoi(argv[2]));
              break;
         }
          else if (atoi(&input) == 3){
              printf("Dondurmek istediginiz yon (Saat yonu -1, tersi 1): ");
              scanf("%s", argv[3]);
              kontroller(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
              break;
         }
          else if (atoi(&input) == 4){
              printf("Dondurme miktari: ");
              scanf("%s", argv[5]);
              kontroller(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
              break;
          }
          else{
              sil(atoi(argv[1]), dizi);
              return 0;
         }
        }
    }
}
