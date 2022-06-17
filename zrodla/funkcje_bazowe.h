#ifndef FUNKCJE_BAZOWE_H
#define FUNKCJE_BAZOWE_H

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "wlasne_typy_danych.h"

/**
 * @brief Funkcja zamieniająca typ wyliczeniowy zgodnosc na napis.
 * 
 * @param arg - wartość zgodności
 * @return char* odpowiedni łańcuch znaków, będący informacją o zgodności
 */
char *dekodujZgodnosc(zgodnosc arg);

/**
 * @brief Zamienia wszystkie znaki liter w łańcuchu na litery małe.
 * 
 * @param lancuch - łańuch znaków do modyfikacji
 */
void toLower(char *lancuch);



#endif