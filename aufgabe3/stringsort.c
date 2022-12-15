/*
 * stringsort.c
 *
 * @author Dominik Bartsch
 * @version 22.04.2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubblesort(int anzahl, char *strings[])
{
    for (int i = anzahl; i > 1; --i)
    {
        // größten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                // Werte tauschen
                char* tmp = strings[j + 1];
                strings[j + 1] = strings[j];
                strings[j] = tmp;
            }
        }
    }

    return;
}

int main(int argc, char *argv[])
{
    // Arraygröße bestimmen
    if (argc != 2)
    {
        fprintf(stderr, "Aufruf: %s Anzahl\n", argv[0]);
        return 1;
    }

    int anzahl = atoi(argv[1]);

    if (anzahl < 1)
    {
        fprintf(stderr, "Anzahl muss mindestens 1 sein\n");
        return 1;
    }

    char **strings = (char **) malloc(anzahl * sizeof (char*));

    // Fehlerbehandlung
    if (strings == NULL)
    {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen");
        return 1;
    }

    // Strings würfeln
    srand((unsigned int) time(NULL));
    int numlen = strlen(argv[1]);
    int outnum = 0;

    printf("Unsortiertes Array:\n");

    for (int i = 0; i < anzahl; ++i)
    {
        int randnum = rand() % anzahl;
        char *randstr = (char*) malloc(1 + numlen * sizeof (char));

        // Fehlerbehandlung
        if (randstr == NULL)
        {
            fprintf(stderr, "Speicherreservierung fehlgeschlagen");
            return 1;
        }

        int tmp = sprintf(randstr, "%d", randnum);
        if (tmp < 0) 
        {
            fprintf(stderr, "Zufälliger String fehlgeschlagen");
            return 1;
        }
        outnum += tmp;

        strings[i] = randstr;
        printf("%s ", strings[i]);
    }

    bubblesort(anzahl, strings);

    // Zahlen ausgeben
    printf("\nSortiertes Array:\n");
    
    char *outstr = malloc(anzahl + outnum * sizeof (char));
    if (outstr == NULL)
    {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen");
        return 1;
    }

    strcpy(outstr, strings[0]);
    for (int i = 1; i < anzahl; ++i)
    {
        if (strcmp(strings[i], strings[i - 1]) == 0)
        {
            strcat(outstr, "*");
        }
        else
        {
            strcat(outstr, " ");
            strcat(outstr, strings[i]);
        }
    }

    printf("%s\n", outstr);
    
    // Speicher freigeben
    for (int i = 0; i < anzahl; ++i)
    {
        free(strings[i]);
    }
    free(strings);
    free(outstr);

    return 0;
}