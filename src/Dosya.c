#include "Dosya.h"

Dosya new_Dosya(char *link)
{
    Dosya dosya = malloc(sizeof(struct DOSYA));
    dosya->fp = fopen(link, "r");
    dosya->satir = 0;
    char tmp[100];

    while (fgets(tmp, 1000, dosya->fp))
    {
        dosya->satir++;
    }

    rewind(dosya->fp);

    return dosya;
}

Kisi *kisiDizisi(const Dosya dosya)
{
    Kisi *kisiler = malloc(dosya->satir * sizeof(struct KISI));
    char tmp[100];
    int counter = 0;
    while (fgets(tmp, 1000, dosya->fp))
    {
        kisiler[counter++] = new_Kisi(tmp);
    }

    return kisiler;
}

int* sayiDizisi(Dosya dosya)
{
    int *sayilar = malloc(dosya->satir * sizeof(int));
    char tmp[100];
    int counter = 0;
    while (fgets(tmp, 1000, dosya->fp))
    {
        sayilar[counter++] = strtol(tmp, NULL, 10);
    }

    return sayilar;
}

void delete_Dosya(const Dosya dosya){
    if(dosya == NULL) return;
    fclose(dosya->fp);
    free(dosya);
}