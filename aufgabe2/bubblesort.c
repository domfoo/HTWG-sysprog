/*
 * bubblesort.c
 *
 * Neugeschriebener Bubblesort angelehnt an Bubblesort.java
 *
 * @author Dominik Bartsch
 * @version 08.04.2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));

    // Arraygroesse einlesen
    if (argc != 2)
    {
        fprintf(stderr, "Aufruf: %s Anzahl\n", argv[0]);
        return 1;
    }

    int anzahl = atoi(argv[1]);
    int *zahlen = malloc(anzahl * sizeof (int));
    // Fehlerbehandlung für malloc
    if (zahlen == NULL) {
        fprintf(stderr, "Speicherreservierung mit malloc() fehlgeschlagen");
        return 1;
    }

    // Zahlen einlesen
    printf("Bitte %d ganze Zahlen eingeben: ", anzahl);
    int k = 0;
    for (int i = 0; i < anzahl; ++i)
    {
        int zahl;
        if (scanf("%d", &zahl) == 1)
        {
            zahlen[i] = zahl;
        }
        else
        {
            break;
        }
        ++k;
    }

    // Array mit zufälligen Zahlen auffüllen
    for (int i = k; i < anzahl; ++i)
    {
        zahlen[i] = rand();
        printf("%d\n", zahlen[i]);
    }

    // Zahlen sortieren
    for (int i = anzahl; i > 1; --i)
    {
        // groesseren Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (zahlen[j] > zahlen[j + 1])
            {
                // Werte tauschen
                int tmp = zahlen[j + 1];
                zahlen[j + 1] = zahlen[j];
                zahlen[j] = tmp;
            }
        }
    }

    // Zahlen ausgeben
    printf("Sortierte Zahlenfolge: \n");
    for (int i = 0; i < anzahl; ++i)
    {
        printf("%d\n", zahlen[i]);
    }

    free(zahlen);
    return 0;
}
