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

SWystapienieZgodnosci *analizujWyrazyZPliku(FILE *plik, char *wyraz_odn, char mode)
{
    // bufor, do którego będą zapisywane wyrazy z pliku znak po znaku
    char bufor[1000];

    // index aktualnej pozycji w buforze
    int idx = 0;

    // aktualnie wczytany znak
    char c;

    // sprawdzenie przekroczenia wielkości bufora
    bool spr_rozm = false;

    // numer linii w pliku - licząc od jednego
    int nr_linii = 1;

    // wynikowa lista
    SWystapienieZgodnosci *wyn = NULL; 

    while (EOF != (c = fgetc(plik)))
    {
        // znak nie jest znakiem pustym i nie jest znakiem innym niż alfanumeryczny,
        // i nie zbliża się do końca bufora
        if(!isspace(c) && !ispunct(c) && !spr_rozm)
        {
            //
            bufor[idx++] = c;
            
            // jeśli znak jest już na drugim miejscu od końca bufora
            if(idx == 998) spr_rozm = true; 
        }
        else
        {
            // jeśli wyraz ma rozmiar 0 - przejdź do kolejnego kroku pętli,
            // wcześniej sprawdzając, czy wczytanym znakiem nie był znak końca pętli
            if(idx == 0) 
            {
                // przejście do nowej linii
                if(c == '\n') ++nr_linii;

                continue;
            }

            // jeśli osiągany jest koniec bufora, ale ostatni wczytany znak jest
            // jeszcze znakiem alfanumerycznym
            if(spr_rozm && !isspace(c) && !ispunct(c))
            {
                bufor[idx++] = c;   // pozycja 998 w buforze                
            }            

            // zakończenie łańcucha znaków
            bufor[idx] = 0;   // indeks powinien mieć numer 999
            idx = 0;

            // wielkość liter w porównywanych wyrazach nie ma znaczenia
            if(mode == '0')
            {   
                toLower(bufor);
                zgodnosc spr_zgod = sprZgodnoscWyrazow(bufor, wyraz_odn);

                // wyrazy są w pewnym stopniu zgodne
                if(spr_zgod == pelna || spr_zgod == niepelna)
                {
                    // w liście wynikowej nie ma jeszcze żadnego elementu
                    if(wyn == NULL)
                    {
                        wyn = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));
                        wyn->nrLinii = nr_linii;
                        wyn->rodzZgodnosci = spr_zgod;
                        wyn->nast = NULL;
                        wyn->poprz = NULL;
                    }

                    // w liście wynikowej są już elementy
                    else
                    {
                        SWystapienieZgodnosci *tmp;
                        tmp = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));
                        tmp->nrLinii = nr_linii;
                        tmp->rodzZgodnosci = spr_zgod;

                        wyn->nast = tmp;    // ostatni element listy wskazuje na nowy element
                        tmp->poprz = wyn;   // nowy element wskazuje na ostatni element listy jako poprzedni
                        tmp->nast = NULL;   // nowy element jest elementem ostatnim na liście
                        wyn = tmp;          // wyn wskazuje na nowy element
                    }
                }
                
                // przejście do nowej linii
                if(c == '\n') ++nr_linii;

                continue;
            }

            // wielkość liter w porównywanych znakach ma znaczenie
            if(mode == '1')
            {
                zgodnosc spr_zgod = sprZgodnoscWyrazow(bufor, wyraz_odn);

                // wyrazy są w pewnym stopniu zgodne
                if(spr_zgod == pelna || spr_zgod == niepelna)
                {
                    // w liście wynikowej nie ma jeszcze żadnego elementu
                    if(wyn == NULL)
                    {
                        wyn = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));
                        wyn->nrLinii = nr_linii;
                        wyn->rodzZgodnosci = spr_zgod;
                        wyn->nast = NULL;
                        wyn->poprz = NULL;
                    }

                    // w liście wynikowej są już elementy
                    else
                    {
                        SWystapienieZgodnosci *tmp;
                        tmp = (SWystapienieZgodnosci *) malloc(sizeof(SWystapienieZgodnosci));
                        tmp->nrLinii = nr_linii;
                        tmp->rodzZgodnosci = spr_zgod;

                        wyn->nast = tmp;    // ostatni element listy wskazuje na nowy element
                        tmp->poprz = wyn;   // nowy element wskazuje na ostatni element listy jako poprzedni
                        tmp->nast = NULL;   // nowy element jest elementem ostatnim na liście
                        wyn = tmp;          // wyn wskazuje na nowy element
                    }
                }
                
                // przejście do nowej linii
                if(c == '\n') ++nr_linii;

                continue;
            }
        }
    }
    
    return wyn;
}