#ifndef WLASNE_TYPY_DANYCH_H
#define WLASNE_TYPY_DANYCH_H

#include <stdio.h>
#include <stdlib.h>

typedef enum zgodnosc 
{
    zerowa = 0,
    pelna = 1, 
    niepelna = 2   
} zgodnosc;

/**
 * @brief Lista dwukierunkowa przechowująca informacje o zgodnościach 
 * odnalezionych w pliku.
 * 
 */
typedef struct SWystapienieZgodnosci
{
    int nrLinii;
    zgodnosc rodzZgodnosci;
    struct SWystapienieZgodnosci *poprz;
    struct SWystapienieZgodnosci *nast;

} SWystapienieZgodnosci;


#endif // WLASNE_TYPY_DANYCH_H