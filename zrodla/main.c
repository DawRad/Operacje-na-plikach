#include <conio.h>

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

    // char wyraz_1[50];
    // char wyraz_2[50];

    // printf("Podaj pierwszy wyraz: ");    
    // scanf("%s", wyraz_1);    
    // printf("\nPodaj drugi wyraz: ");
    // scanf("%s", wyraz_2);

    // zgodnosc wynikSpr = sprZgodnoscWyrazow(wyraz_1, wyraz_2);
    // printf("\nPodane wyrazy to (odpowiednio 1-szy i 2-gi): %s i %s", wyraz_1, wyraz_2);
    // printf("\nWynik testu zgodnosci: %s\n", dekodujZgodnosc(wynikSpr));

    SWystapienieZgodnosci *glowa = NULL, *ogon = NULL;

    dodKon(&glowa, &ogon, 77, niepelna);
    dodPocz(&glowa, &ogon, 1, pelna);
    dodPocz(&glowa, &ogon, 2, niepelna);
    dodPocz(&glowa, &ogon, 12, pelna);
    dodKon(&glowa, &ogon, 88, niepelna);

    wypiszPocz(glowa);
    wypiszKon(ogon);

    SWystapienieZgodnosci *temp = NULL;
    temp = zwrocPojElemKon(ogon, 4);

    printf("\n\n4-ty element od początku listy:\nNumer linii: %d\nRodzaj zgodnosci: %s\n", temp->nrLinii, dekodujZgodnosc(temp->rodzZgodnosci));

    wyczyscListePocz(glowa);

    // fclose(plikWej);

    printf("\nNaci");
    getch();

    return 0;
}