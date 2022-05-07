#ifndef OYUN_H
#define OYUN_H

#include "Dosya.h"
#include "Kisi.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

struct OYUN{
    Kisi* kisiler;
    int* sayilar;
    int masaPara;
    int tur;
    int kisiSayisi;

};

typedef struct OYUN* Oyun;

Oyun new_Oyun();
void start(const Oyun);
void kisiSirala(const Oyun);
void yazdir(const Oyun);



#endif