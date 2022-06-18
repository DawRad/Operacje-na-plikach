# Operacje-na-plikach
Projekt zawierający działania na plikach w języku C. Wczytuje podany plik i analizuje tekst z pliku pod kątem znalezienia wyrazów podobnych do 
wyrazu podanego jako odniesienie.

## Główne funkcje
<p align="justify">
Program pobiera wyrazy z pliku znak po znaku. Są one zapisywane do odpowiednio długiego bufora - tablicy znaków. Potem każdy wyraz jest sprawdzany pod 
kątem zgodności z wyrazem odniesienia. W zależności od wybranej opcji podczas porównywania wyrazów wielkość liter jest brana pod uwagę lub nie. Wynik 
analizy jest zapisywany w postaci listy dwukierunkowej, której elementy przechowują informację o każdej zgodności z wyrazem odniesienia, która wystąpiła
w pliku. Zgodność jest określana wg 3-stopniowej skali: pełna, niepełna lub zerowa.
</p>

## Własne struktury danych
<p align="justify">
Na potrzeby projektu utworzono dwa nowe typy danych. Pierwszym jest struktura rekurencyjna elementu listy dwukierunkowej, przechowującego dane o linii, 
w której wystąpiła zgodność z wyrazem odniesienia oraz o rodzaju zgodności. 

Drugim jest typ wyliczeniowy określający stany zgodności wyrazów. Oba typy są zdefiniowane w pliku nagłówkowym "wlasne_typy_danych.h". 
  
Ponadto, w pliku 
</p>
