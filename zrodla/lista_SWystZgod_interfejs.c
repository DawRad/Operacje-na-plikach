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

SWystapienieZgodnosci *zwrocPojElemPocz(SWystapienieZgodnosci *glowa, int licz)
{
    SWystapienieZgodnosci *temp = glowa;

    while(temp != NULL && temp->nast != NULL && licz > 0)
    {
        temp = temp->nast;
        --licz;
    }

    return temp;
}

SWystapienieZgodnosci *zwrocPojElemKon(SWystapienieZgodnosci *ogon, int licz)
{
    SWystapienieZgodnosci *temp = ogon;

    while (temp != NULL && temp->poprz != NULL && licz >0)
    {
        temp = temp->poprz;
        --licz;
    }

    return temp;
}

SWystapienieZgodnosci *zwrocElemWgParamPocz(SWystapienieZgodnosci *glowa, int nr_linii, zgodnosc param_zgod)
{
    SWystapienieZgodnosci *wyn = NULL, *tmp = NULL, *nowy = NULL;
    tmp = glowa;
    wyn = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));
    wyn->nast = NULL;
    wyn->poprz = NULL;

    // w przypadku, gdy jako parametr zostanie podana pusta lista
    if(glowa == NULL) return NULL;

    // numer linii i rodzaj zgodności mogą mieć dowolne wartości
    if(nr_linii = -1 && param_zgod == dowolna) 
    {
        *wyn = *tmp;
        wyn->nast = NULL;
        wyn->poprz = NULL;
        tmp = tmp->nast;

        while (tmp != NULL)
        {
            nowy = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));
            *nowy = *tmp;
            // wyn->
            // nowy->poprz
        }
        
    }    

    while (tmp != NULL)
    {
        // wartość numeru linii jest dowolna
        if(nr_linii == -1)
        {
            if(param_zgod == tmp->rodzZgodnosci)
            {

            }
        }

        // wartość rodzaju zgodności dowolna
        if(param_zgod == dowolna)
        {
            if (nr_linii == tmp->nrLinii)
            {
                /* code */
            }
            
        }
    }
    

    return wyn;
}

SWystapienieZgodnosci *zwrocElemWgParamKon(SWystapienieZgodnosci *ogon, int nr_linii, zgodnosc param_zgod)
{
    
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