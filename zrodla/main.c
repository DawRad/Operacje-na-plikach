#include <conio.h>

#include "funkcje.h"

int maxBuffLngth = 50;

int main(void)
{
    FILE *plikWej;
    plikWej = fopen("test.txt", "r+");
    if(!plikWej) 
    {
        printf("*** Blad pliku! ***");
        return 1;
    }

    SWystapienieZgodnosci *glowa = NULL, *ogon = NULL;

    ogon = analizujWyrazyZPliku(plikWej, "dla", '0');
    glowa = znajdzGlowe(ogon);

    fclose(plikWej);    

    wypiszPocz(glowa);
    wypiszKon(ogon);
    
    wyczyscListePocz(glowa);    

    printf("\nNaci");
    getch();

    return 0;
}