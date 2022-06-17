#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "lista_SWystZgod_interfejs.h"

/**
 * @brief Funkcja wyznacza rozmiar tablicy znaków z tekstem.
 * 
 * @param txt - tekst, którego rozmiar ma zostać wyznaczony
 * @return rozmiar tablicy znaków, jako typ int
 */
int wyznaczRozmTekstu(char *txt);

/**
 * @brief Funkcja wypisująca pojedyncze wyrazy z pliku tekstowego.
 * 
 * @param plik_we - zmienna plikowa pliku wejściowego
 */
void wypiszWyrazyZPliku(FILE *plik_we);

/**
 * @brief Sprawdza w jakim stopniu jeden wyraz pokrywa się z drugim.
 * 
 * @param wyraz_1 - wyraz sprawdzany
 * @param wyraz_2 - wyraz odniesienia
 * @return enum zgodnosc 
 */
zgodnosc sprZgodnoscWyrazow(char *wyraz_1, char *wyraz_2);

/**
 * @brief 
 * 
 * @param plik - przeszukiwany plik
 * @param wyraz_odn - wyraz odniesienia, czyli ciąg znaków, który jest poszukiwany w tekście
 * @param mode - sposób porównywania wyrazów:
 * \li 0 (domyślnie) - nie uwzględnia wielkości liter,
 * \li 1 - uwzględnia wielkość liter.
 * @return SWystapienieZgodnosci* listę wystąpień wyrazów zgodnych z wyrazem odniesienia
 */
SWystapienieZgodnosci *analizujWyrazyZPliku(FILE *plik, char *wyraz_odn, int mode = 0);


#endif // FUNKCJE_H