#ifndef LISTA_SWYSTZGOD_INTERFEJS_H
#define LISTA_SWYSTZGOD_INTERFEJS_H

#include "funkcje_bazowe.h"

/**
 * @brief Tworzy i dodaje element na początek listy SWystapienieZgodnosci.
 * 
 * @param glowa - wskaźnik pierwszego elementu listy, w trakcie działania funkcji
 * zostaje zamieniony
 * @param ogon - wskaźnik ostatniego elementu listy. Zmieniany w trakcie działania, jeśli
 * lista jest pusta.
 * @param nr_linii - numer linii w pliku, w której wystąpiła zgodność
 * @param rodz_zgod - rodzaj zgodności, który dotyczy danego wystąpienia
 */
void dodPocz(SWystapienieZgodnosci **glowa, SWystapienieZgodnosci **ogon, int nr_linii, zgodnosc rodz_zgod);

/**
 * @brief Tworzy i dodaje element na koniec listy SWystapienieZgodnosci.
 * 
 * @param glowa - wskaźnik pierwszego elementu listy, w trakcie działania funkcji
 * zostaje zamieniony
 * @param ogon - wskaźnik ostatniego elementu listy. Zmieniany w trakcie działania, jeśli
 * lista jest pusta.
 * @param nr_linii - numer linii w pliku, w której wystąpiła zgodność
 * @param rodz_zgod - rodzaj zgodności, który dotyczy danego wystąpienia
 */
void dodKon(SWystapienieZgodnosci **glowa, SWystapienieZgodnosci **ogon, int nr_linii, zgodnosc rodz_zgod);

/**
 * @brief Wypisuje w konsoli elementy listy zaczynając od
 * elementu pierwszego.
 * 
 * @param glowa - wskaźnik pierwszego elementu listy
 */
void wypiszPocz(SWystapienieZgodnosci *glowa);

/**
 * @brief Wypisuje w konsoli elementy listy zaczynając od elementu
 * ostatniego.
 * 
 * @param ogon - wskaźnik ostatniego elementu listy
 */
void wypiszKon(SWystapienieZgodnosci *ogon);

/**
 * @brief Zwalnia pamięć zaalokowaną dla elementów listy.
 * 
 * @param glowa - wskaźnik pierwszego elementu listy
 */
void wyczyscListePocz(SWystapienieZgodnosci *glowa);

#endif // LISTA_SWYSTZGOD_INTERFEJS_H