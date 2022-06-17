#include "funkcje_bazowe.h"

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

void toLower(char *lancuch)
{
    int i = 0;
    while(*(lancuch + i) != 0)
    {
        if(*(lancuch + i) >= 'A' && *(lancuch + i) <= 'Z') *(lancuch + i) = *(lancuch + i) + ('a' - 'A');

        ++i;
    }
}

