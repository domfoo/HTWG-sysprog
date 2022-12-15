/*
 * stringsort-optimiert.c
 *
 * @author Dominik Bartsch
 * @version 30.04.2022
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubblesort(char *strings, size_t anzahl, size_t m, int (*comp)(void *, void *))
{
    char *tmp = (char*) malloc(m * sizeof (char));
    
    for (int i = anzahl; i > 1; --i)
    {
        // größten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (comp(&strings[j * m], &strings[(j + 1) * m]) > 0)
            {
                // Werte tauschen
                memcpy(tmp, &strings[(j + 1) * m], m);
                memcpy(&strings[(j + 1) * m], &strings[j * m], m);
                memcpy(&strings[j * m], tmp, m);
            }
        }
    }
    
    free(tmp);
}

int main(int argc, char *argv[])
{
    // Arraygroesse bestimmen
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

    int m = strlen(argv[1]) + 1;
    char *strings = (char *) malloc(anzahl * m * sizeof (char));

    if (strings == NULL)
    {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen");
        return 1;
    }

    // Strings wuerfeln
    srand((unsigned int) time(NULL));
    int platzbedarf = 0;

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < anzahl; ++i)
    {
        int randnum = rand() % anzahl;
        platzbedarf += sprintf(&strings[i * m], "%d", randnum);
        printf("%s ", &strings[i * m]);
    }

    // Strings sortieren
    bubblesort(strings, anzahl, m, (int (*)(void*, void*))strcmp);

    // Strings ausgeben
    char *outstr = malloc(anzahl + platzbedarf * sizeof (char));
    if (outstr == NULL)
    {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen");
        return 1;
    }

    printf("\nSortiertes Array:\n");

    strcpy(outstr, &strings[0]);
    for (int i = 1; i < anzahl; ++i)
    {
        if (strcmp(&strings[i * m], &strings[(i - 1) * m]) == 0)
        {
            strcat(outstr, "*");
        }
        else
        {
            strcat(outstr, " ");
            strcat(outstr, &strings[i * m]);
        }
    }
    printf("%s\n", outstr);

    // Heap-Speicher freigeben
    free(strings);
    free(outstr);

    return 0;
}
