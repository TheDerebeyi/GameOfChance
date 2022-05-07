#include "Oyun.h"

Oyun new_Oyun(){
    Oyun oyun = malloc(sizeof(struct OYUN));
    
    Dosya tmp = new_Dosya("../Kisiler.txt");
    oyun->kisiSayisi = tmp->satir;

    oyun->kisiler = kisiDizisi(tmp);

    delete_Dosya(tmp);

    oyun->sayilar = sayiDizisi(new_Dosya("../Sayilar.txt"));

    oyun->masaPara = 0;

    oyun->tur = 0;
}

void start(const Oyun oyun){
    /*kisiSirala(oyun);*/
   /* for(int i = 0; i < 1000; i++){
        printf("%.2lf, %s\n",oyun->kisiler[i]->para, oyun->kisiler[i]->ad);
    }*/

    while(oyun->kisiSayisi!=0){
        for(int i = 0; i < oyun->kisiSayisi; i++){
            oyun->masaPara += oyna(oyun->kisiler[i]);
            if(kazandiMi(oyun->kisiler[i], oyun->sayilar[oyun->tur])){
                oyun->masaPara -= oyun->kisiler[i]->sonYatirilanMiktar * 10;
            }
        }
        oyun->tur++;
        kisiSirala(oyun);
        yazdir(oyun);
    }
}

void kisiSirala(const Oyun oyun){
    for(int i = 0; i < oyun->kisiSayisi - 1; i++){
        int degisim = 0;
        for(int j = 0; j < oyun->kisiSayisi - 1; j++){
            if(oyun->kisiler[j]->para < oyun->kisiler[j+1]->para){
                Kisi tmp = oyun->kisiler[j+1];
                oyun->kisiler[j+1] = oyun->kisiler[j];
                oyun->kisiler[j] = tmp;
                int degisim = 1;
            }
        }
        if(degisim = 0) break;
    }

    for(int i = 0; i < oyun->kisiSayisi; i++){
        if(oyun->kisiler[i]->para < 1000){
            oyun->kisiSayisi = i;
            break;
        }
    }
}

void yazdir(const Oyun oyun){
    /*system("clear");*/

    printf("\n\n\n\n\n\n\t\t\t\t");
    for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
    printf("\n\t\t\t\t##\t\tSANSLI SAYI: %-2d\t\t   ##\n\t\t\t\t", oyun->sayilar[oyun->tur]);
    for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
    printf("\n\t\t\t\t");
    for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
    printf("\n\t\t\t\t##\t\tTUR: %-3d\t\t   ##\n\t\t\t\t##\tMASA BAKIYE: %-10.2lf TL\t   ##\n\t\t\t\t##\t\t\t\t\t   ##\n\t\t\t\t##", oyun->tur,oyun->masaPara);
    for(int i = 0 ; i <41; i++){
        printf("-");
    }
    printf("##\n\t\t\t\t##\t\tEN ZENGIN KISI\t\t   ##\n\t\t\t\t##\t\t%-22s     ##\n\t\t\t\t##\tBAKIYESI: %-10.2lf TL\t\t   ##\n\t\t\t\t##\t\t\t\t\t   ##\n\t\t\t\t", oyun->kisiler[0]->ad, mevcutPara(oyun->kisiler[0]));
        for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
}