#include "Kisi.h"

Kisi new_Kisi(char* string){
    char* tmp, *saveptr;

    /*Kişiler dosyalardan Rafaela Carroll#79289.71#0.89#1 formatında gelmektedir
      Burada # karakterine göre bu karakter dizilerini parçalıyoruz.

      strtod double dönüşümleri, strol integer dönüşümleri için kullanıldı.
    */

    Kisi kisi = malloc(sizeof(struct KISI));
    kisi->ad = strtok_r(string, "#", &saveptr);
    kisi->para = strtod(strtok_r(NULL, "#", &saveptr), &tmp);
    kisi->neKadar = strtod(strtok_r(NULL, "#", &saveptr), &tmp);
    kisi->sayi = strtol(strtok_r(NULL, "#", &saveptr),NULL,10);
    kisi->sonYatirilanMiktar = 0;
    return kisi;
}

double oyna(const Kisi kisi){       //Oyuna dahil olmak için ne kadar bahis yatıracaklarını hesapladığımız kısım
    kisi->sonYatirilanMiktar = kisi->para * kisi->neKadar;
    kisi->para -= kisi->sonYatirilanMiktar;
    return kisi->sonYatirilanMiktar;
}

int kazandiMi(const Kisi kisi, int cikanNum){   //Kazanma kontrolü sonucunda paraları yatırdıkları bahse göre artıyor.
    if(cikanNum!= kisi->sayi) return 0;         //Burada int geri döndürmemin nedeni programa masa bakiyesini ayarlaya-
                                                //bilmesi için sinyal sağlamak.
    kisi->para += kisi->sonYatirilanMiktar * 10;
    return 1;
}

double mevcutPara(const Kisi kisi){
    return kisi->para;
}

void delete_Kisi(const Kisi kisi){
    if(kisi == NULL) return;
    free(kisi->ad);
    free(kisi);
}