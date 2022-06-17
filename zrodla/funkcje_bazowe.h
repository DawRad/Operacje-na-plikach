#ifndef FUNKCJE_BAZOWE_H
#define FUNKCJE_BAZOWE_H

#include <string.h>

#include "wlasne_typy_danych.h"

/**
 * @brief Funkcja zamieniająca typ wyliczeniowy zgodnosc na napis.
 * 
 * @param arg - wartość zgodności
 * @return char* odpowiedni łańcuch znaków, będący informacją o zgodności
 */
char *dekodujZgodnosc(zgodnosc arg);

#endif