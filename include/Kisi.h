#ifndef KISI_H
#define KISI_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct KISI{
    char* ad;
    double para;
    double neKadar;
    int sayi;
    int sonYatirilanMiktar;
};

typedef struct KISI* Kisi;

Kisi new_Kisi(char*);
void oyna(const Kisi, int);
double mevcutPara(const Kisi);

#endif