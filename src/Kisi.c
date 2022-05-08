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

double oyna(const Kisi kisi){
    kisi->sonYatirilanMiktar = kisi->para * kisi->neKadar;
    kisi->para -= kisi->sonYatirilanMiktar;
    return kisi->sonYatirilanMiktar;
}

int kazandiMi(const Kisi kisi, int cikanNum){
    if(cikanNum!= kisi->sayi) return 0;

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