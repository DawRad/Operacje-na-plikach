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
 * @brief Zwraca n-ty element względem początku listy.
 * 
 * Numerowanie elementów zaczyna się od n == 0. Jeśli podany numer elementu 
 * wykracza poza liczbę elementów w liście, to zwraca koniec listy. Jeśli lista pusta - 
 * zwraca NULL.
 * @param glowa - wskaźnik pierwszego elementu listy
 * @param licz - numer elementu, który ma zostać zwrócony
 * @return SWystapienieZgodnosci* wskaźnik do szukanego elementu
 */
SWystapienieZgodnosci *zwrocPojElemPocz(SWystapienieZgodnosci *glowa, int licz);

/**
 * @brief Zwraca n-ty element względem końca listy.
 * 
 * Numerowanie elementów zaczyna się od n == 0. Jeśli podany numer elementu 
 * wykracza poza liczbę elementów w liście, to zwraca początek listy. Jeśli lista pusta - 
 * zwraca NULL.
 * @param ogon - wskaźnik ostatniego elementu listy
 * @param licz - numer elementu, który ma zostać zwrócony
 * @return SWystapienieZgodnosci* wskaźnik do szukanego elementu
 */
SWystapienieZgodnosci *zwrocPojElemKon(SWystapienieZgodnosci *ogon, int licz);

/**
 * @brief Znajduje podzbiór elementów spełniających podane kryteria.
 * 
 * Lista jest przeszukiwana od początku. 
 * @param glowa - wskaźnik pierwszego elementu listy
 * @param nr_linii - numer linii danego elementu
 * \li jeśli równy -1, to brana jest dowolna wartość
 * @param param_zgod - rodzaj zgodności elementu
 * \li jeśli równy "dowolna", to brana jest dowolna wartość
 * @return SWystapienieZgodnosci* początek listy znalezionych elementów. Zwraca element równy NULL, jeśli
 * nie zostały znalezione żadne elementy spełniające podane kryteria.
 */
SWystapienieZgodnosci *zwrocElemWgParamPocz(SWystapienieZgodnosci *glowa, int nr_linii, zgodnosc param_zgod);

/**
 * @brief Znajduje podzbiór elementów spełniających podane kryteria.
 * 
 * Lista jest przeszukiwana od końca. 
 * @param ogon - wskaźnik ostatniego elementu listy
 * @param nr_linii - numer linii danego elementu
 * \li jeśli równy -1, to brana jest dowolna wartość
 * @param param_zgod - rodzaj zgodności elementu
 * \li jeśli równy "dowolna", to brana jest dowolna wartość
 * @return SWystapienieZgodnosci* początek listy znalezionych elementów. Zwraca element równy NULL, jeśli
 * nie zostały znalezione żadne elementy spełniające podane kryteria.
 */
SWystapienieZgodnosci *zwrocElemWgParamKon(SWystapienieZgodnosci *ogon, int nr_linii, zgodnosc param_zgod);

/**
 * @brief Znajduje głowę listy dwukierunkowej SWystapienieZgodnosci.
 * 
 * @param ogon - wskaźnik ostatniego elementu listy
 * @return SWystapienieZgodnosci* wskaźnik pierwszego elementu listy
 */
SWystapienieZgodnosci *znajdzGlowe(SWystapienieZgodnosci *ogon);

/**
 * @brief Zwalnia pamięć zaalokowaną dla elementów listy.
 * 
 * @param glowa - wskaźnik pierwszego elementu listy
 */
void wyczyscListePocz(SWystapienieZgodnosci *glowa);

#endif // LISTA_SWYSTZGOD_INTERFEJS_H