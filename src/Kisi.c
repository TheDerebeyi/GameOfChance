#include "Kisi.h"

Kisi new_Kisi(char* string){
    char* tmp, *saveptr;

    Kisi kisi = malloc(sizeof(struct KISI));
    kisi->ad = strtok_r(string, "#", &saveptr);
    kisi->para = strtod(strtok_r(NULL, "#", &saveptr), &tmp);
    kisi->neKadar = strtod(strtok_r(NULL, "#", &saveptr), &tmp);
    kisi->sayi = strtol(strtok_r(NULL, "#", &saveptr),NULL,10);
    kisi->sonYatirilanMiktar = 0;
    return kisi;
}

void oyna(const Kisi kisi, int cikanNum){
    int tutar = kisi->para * kisi->neKadar;
    kisi->para -= tutar;

    if(cikanNum!= kisi->sayi) return;

    kisi->para += kisi->sonYatirilanMiktar * 10;
}

double mevcutPara(const Kisi kisi){
    return kisi->para;
}