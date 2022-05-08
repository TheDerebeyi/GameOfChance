
#include "Oyun.h"
#include "stdio.h"
#include "stdlib.h"

int main(int args, char *argv[])
{

    Oyun oyun = new_Oyun();
    start(oyun);
    delete_Oyun(oyun);
    getchar();
}