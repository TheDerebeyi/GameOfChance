#include "Oyun.h"

Oyun new_Oyun(){
    Oyun oyun = malloc(sizeof(struct OYUN));
    
    Dosya tmp = new_Dosya("../Kisiler.txt");
    oyun->kisiSayisi = tmp->satir;              //Satır sayısını aldık çünkü programda ilerleyen zamanlarda kişi dizisinin
                                                //büyüklüğü program tarafından oyunda kalan kişi sayısını belirlemede kullanılacak.
    oyun->kisiler = kisiDizisi(tmp);

    delete_Dosya(tmp);


    tmp = new_Dosya("../Sayilar.txt");

    oyun->sayilar = sayiDizisi(tmp);
    
    delete_Dosya(tmp);

    oyun->masaPara = 0;

    oyun->tur = 0;
}

void start(const Oyun oyun){
    while(oyun->kisiSayisi!=0){         //Kişi sayısından her turun sonunda kişileri sıralama esnasında elenenler çıkartılacak. Oyun bittiğinde 0'a eşit olacak.
        for(int i = 0; i < oyun->kisiSayisi; i++){          //Tüm kişilerin bahis yapabilmesi için dizi baştan sona taranacak.
            oyun->masaPara += oyna(oyun->kisiler[i]);       // - kişinin ne kadar bahis yaptığı
            if(kazandiMi(oyun->kisiler[i], oyun->sayilar[oyun->tur])){          // - kazanma durumunda masadan para ödemesi
                oyun->masaPara -= oyun->kisiler[i]->sonYatirilanMiktar * 10;
            }
        }
        oyun->tur++;
        kisiSirala(oyun);           //Kişi sıralamanın amacı en zengin kişiyi ve elenen kişileri tespit etmek.
                                    //Dizi fiziksel olarak tüm kişileri içerse de programın gözünde sadece oyuna kalanları içermektedir.
        yazdir(oyun);
    }


    //Bitiş ekranı

    system("cls");

    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t");
    for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
    printf("\n\t\t\t\t##\t\tTUR: %-3d\t\t   ##\n\t\t\t\t##\tMASA BAKIYE: %-10.2lf TL\t   ##\n\t\t\t\t##\t\t\t\t\t   ##\n\t\t\t\t##", oyun->tur,oyun->masaPara);
    for(int i = 0 ; i <41; i++){
        printf("-");
    }
    printf("##\n\t\t\t\t##\t\tOYUN BITTI\t\t   ##\n\t\t\t\t##\t\t\t\t\t   ##\n\t\t\t\t##\t\t\t\t\t   ##\n\t\t\t\t##\t\t\t\t\t   ##\n\t\t\t\t");
        for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
}

void kisiSirala(const Oyun oyun){
    for(int i = 0; i < oyun->kisiSayisi - 1; i++){              // Bubble sort
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

    for(int i = 0; i < oyun->kisiSayisi; i++){              //Dizi büyükten küçüğe sıralandığı için diziden elenenleri çıkarmak için
        if(oyun->kisiler[i]->para <= 1000){                 //elenmiş ilk ismi çıkarmak yeterli.
            oyun->kisiSayisi = i;                           //Çıkarma işlemi fiziksel değil, dizinin boyutu tespit ettiğimiz bu elenecek kişinin
            break;                                          //indisiymiş gibi göstertiliyor. Bu sayede bu kişi ve ondan daha az paraya sahip tüm kişiler    
        }                                                   //oyundan eleniyor.
    }
}

void yazdir(const Oyun oyun){
    system("cls");

    printf("\n\n\n\n\n\n\t\t\t\t");
    for (int i = 0; i < 45; i++)
    {
        printf("#");
    }
    printf("\n\t\t\t\t##\t\tSANSLI SAYI: %-2d\t\t   ##\n\t\t\t\t", oyun->sayilar[oyun->tur-1]);
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


void delete_Oyun(const Oyun oyun){
    if(oyun == NULL) return;

    free(oyun->sayilar);
    free(oyun->kisiler);

    free(oyun);
}
