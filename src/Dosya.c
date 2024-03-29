#include "Dosya.h"

Dosya new_Dosya(char *link)
{
    Dosya dosya = malloc(sizeof(struct DOSYA));
    dosya->fp = fopen(link, "r");
    dosya->satir = 0;
    char tmp[100];

    while (fgets(tmp, 1000, dosya->fp))     //Hangi dosya aktarılırsa aktarılsın satır sayısını burada dosyadan hesaplıyoruz.
    {                                       //Bunu yapmamın sebebi dinamik bir sistem oluşturmak.
        dosya->satir++;
    }

    rewind(dosya->fp);

    return dosya;
}

Kisi *kisiDizisi(const Dosya dosya)
{
    Kisi *kisiler = malloc(dosya->satir * sizeof(struct KISI));
    int counter = 0;

    while (counter != dosya->satir)             //Dosyadaki her satır bir kişiyi temsil ettiğinden her satır okunup
    {                                           //O satırdan bir kişi nesnesi oluşturuluyor. Bu kişiler bir dizide tutularak
        char* tmp= malloc(sizeof(char)*100);    //oyun sistemine gönderilecek.
        fgets(tmp, 100, dosya->fp);
        kisiler[counter]= new_Kisi(tmp);
        free(tmp);
        counter++;
    }

    return kisiler;
}

int* sayiDizisi(Dosya dosya)
{
    int *sayilar = malloc(dosya->satir * sizeof(int));
    char tmp[100];
    int counter = 0;
    while (fgets(tmp, 100, dosya->fp))
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