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