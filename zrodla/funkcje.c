#include "funkcje.h"


int wyznaczRozmTekstu(char *txt)
{
    int wynik = 0;

    while(*(txt + wynik) != 0) wynik++;

    return wynik;
}

void wypiszWyrazyZPliku(FILE *plik_we)
{
    char wyraz[100];    
    
    while(!feof(plik_we))
    {
        fscanf(plik_we, "%s", wyraz);
        printf("\n---%s---\tRozmiar wyrazu: %d\n", wyraz, wyznaczRozmTekstu(wyraz));
    }
}

zgodnosc sprZgodnoscWyrazow(char *wyraz_1, char *wyraz_2)
{
    // wartości rozmiarów łańcuchów znaków
    int rozm_1 = wyznaczRozmTekstu(wyraz_1);
    int rozm_2 = wyznaczRozmTekstu(wyraz_2);

    // jeśli długość wyrazu pierwszego jest mniejsza niż drugiego, to 
    // brak zgodności
    if(rozm_1 < rozm_2) return zerowa;

    // przypadek, gdy rozmiary obu wyrazów są takie same
    if(rozm_1 == rozm_2)
    {
        int i = 0;

        while(*(wyraz_1 + i) != 0 || *(wyraz_2 + i) != 0)
        {
            // jeśli któryś element pierwszego wyrazu będzie inny
            // niż odpowiadający mu wyraz drugiego, to brak zgodności
            if(*(wyraz_1 + i) != *(wyraz_2 + i)) return zerowa;            
            i++;
        } 

        // jeśli powyższa pętla przejdzie, to znaczy, że wyrazy są takie same
        return pelna;
    }

    // przypadek, gdy rozmiar pierwszego jest większy niż drugiego
    if(rozm_1 > rozm_2)
    {
        for(int i = 0; i <= (rozm_1 - rozm_2); i++)
        {
            for(int j = 0; j < rozm_2; j++)
            {
                // jeśli poniższy warunek spełniony, to znaczy, że
                // w tej pętli nie wykryto zgodności wyrazów
                // należy przejść do kolejnej iteracji pętli zewnętrznej
                if(*(wyraz_1 + j + i) != *(wyraz_2 + j)) break;

                // jeśli nie wykryto niezgodności w warunku powyżej i jest to ostatnia 
                // iteracja pętli wewnętrznej - wyrazy są zgodne nie w pełni
                if(j == (rozm_2 - 1)) return niepelna;
            }
        }

        // jeśli pętla najbardziej zewnętrzna przejdzie, to znaczy, że 
        // wyrazy nie są zgodne
        return zerowa;
    }
}

char *dekodujZgodnosc(zgodnosc arg)
{
    switch(arg)
    {
        case zerowa:
        return "wyrazy nie sa zgodne";

        case pelna:
        return "wyrazy sa w pelni zgodne";

        case niepelna:
        return "wyrazy sa czesciowo zgodne";

        default:
        return "zgodnosc wyrazow nieokreslona";
    }
}