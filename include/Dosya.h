#ifndef DOSYA_H
#define DOSYA_H

#include "Kisi.h"
#include "stdio.h"
#include "stdlib.h"

struct DOSYA{
    FILE* fp;
    int satir;
};

typedef struct DOSYA* Dosya;

Dosya new_Dosya(char*);
Kisi* kisiDizisi(const Dosya);
int* sayiDizisi(const Dosya);
void delete_Dosya(const Dosya);

#endif