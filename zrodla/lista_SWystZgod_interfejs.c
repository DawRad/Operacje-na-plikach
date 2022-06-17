#include "lista_SWystZgod_interfejs.h"

void dodPocz(SWystapienieZgodnosci **glowa, SWystapienieZgodnosci **ogon, int nr_linii, zgodnosc rodz_zgod)
{
    SWystapienieZgodnosci *newElem;
    newElem = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));

    newElem->nrLinii = nr_linii;
    newElem->rodzZgodnosci = rodz_zgod;

    if(*glowa == NULL)
    {
        newElem->nast = *glowa;
        newElem->poprz = NULL;
        *glowa = newElem;
        *ogon = newElem;
    }
    else
    {
        (*glowa)->poprz = newElem;
        newElem->nast = *glowa;
        newElem->poprz = NULL;
        *glowa = newElem;
    }
}

void dodKon(SWystapienieZgodnosci **glowa, SWystapienieZgodnosci **ogon, int nr_linii, zgodnosc rodz_zgod)
{
    SWystapienieZgodnosci *newElem;
    newElem = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));

    newElem->nrLinii = nr_linii;
    newElem->rodzZgodnosci = rodz_zgod;

     if(*ogon == NULL)
    {
        newElem->nast = NULL;
        newElem->poprz = *ogon;
        *glowa = newElem;
        *ogon = newElem;
    }
    else
    {
        (*ogon)->nast = newElem;
        newElem->poprz = *ogon;
        newElem->nast = NULL;
        *ogon = newElem;
    }
}

void wypiszPocz(SWystapienieZgodnosci *glowa)
{
    SWystapienieZgodnosci *temp = glowa;

    printf("\n\n");
    printf("Lista od poczatku:\n");
    
    while(temp != NULL) 
    {
        printf("Numer linii: %d\nRodzaj zgodności: %s\n\n", temp->nrLinii, dekodujZgodnosc(temp->rodzZgodnosci));
        temp = temp->nast;
    }
}

void wypiszKon(SWystapienieZgodnosci *ogon)
{
    SWystapienieZgodnosci *temp = ogon;

    printf("\n\n");
    printf("Lista od konca:\n");
    
    while(temp != NULL) 
    {
        printf("Numer linii: %d\nRodzaj zgodności: %s\n\n", temp->nrLinii, dekodujZgodnosc(temp->rodzZgodnosci));
        temp = temp->poprz;
    }
}

void wyczyscListePocz(SWystapienieZgodnosci *glowa)
{
    SWystapienieZgodnosci *temp;

    while(glowa != NULL)
    {
        temp = glowa;
        glowa = glowa->nast;
        free(temp);
    }
}