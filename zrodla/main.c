#include "funkcje.h"

int maxBuffLngth = 50;

int main(void)
{
    // FILE *plikWej;
    // plikWej = fopen("jedyny_pierscien.txt", "r+");
    // if(!plikWej) 
    // {
    //     printf("*** Blad pliku! ***");
    //     return 1;
    // }

    // char *txtStream;
    // fscanf(plikWej, "%s", txtStream);
    // printf("Wczytany tekst z pliku: \n\"%s\"\nTekst ma rozmiar: %d", txtStream, wyznaczRozmTekstu(txtStream));

    // fscanf(plikWej, "%s", txtStream);
    // printf("\n\nWczytany ponownie tekst z pliku: \n\"%s\"\nTekst ma rozmiar: %d", txtStream, wyznaczRozmTekstu(txtStream));
    
    // fgets(txtStream, maxBuffLngth, plikWej);     
    // printf("\n\nWczytana linia tekstu z pliku: \n\"%s\"\n", txtStream);

    // wypiszWyrazyZPliku(plikWej);

    // char *wyraz;  
    
    // while(!feof(plikWej))
    // {
    //     fscanf(plikWej, "%s", wyraz);
    //     printf("\n---%s---\n", wyraz);        
    // }

    char wyraz_1[] = "wodolot";
    char wyraz_2[] = "wodorower";

    zgodnosc wynikSpr = sprZgodnoscWyrazow(wyraz_1, wyraz_2);
    printf("Podane wyrazy to (odpowiednio 1-szy i 2-gi): %s i %s", wyraz_1, wyraz_2);
    printf("\nWynik testu zgodnosci: %s", dekodujZgodnosc(wynikSpr));


    // fclose(plikWej);

    return 0;
}