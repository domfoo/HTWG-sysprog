#include "leistung.h"
#include "spo3_ain2.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_VALUE(v) STR(v)
#define STR(s) #s

bool leistung_einlesen(leistung* leistung)
{
    if (scanf("%" STR_VALUE(MODULNAME_LENGTH) "s", leistung->modulname) != 1)
    {
        fprintf(stderr, "Eingabefehler!\n");
        return false;
    }
    
    if (scanf("%d", &leistung->note) == 1)
    {
        leistung->leistungsart = benotet;
    }
    else if (scanf("%c", &leistung->status) == 1)
    {
        leistung->leistungsart = unbenotet;
    }
    else
    {
        fprintf(stderr, "Eingabefehler!\n");
        return false;
    }
        
    // Unterstriche ersetzen
    for (;;) {
        char *c = strchr(leistung->modulname, '_');
        if (c != NULL) {
            *c = ' ';
        }
        else
        {
            break;
        }
    }

    return true;
}

static void ausgeben_unbenotet(char status)
{
    if (status == 'B')
    {
        printf("bestanden");
    }
    else if (status == 'N')
    {
        printf("nicht bestanden");
    }
    else
    {
        printf("Fehler: %c", status);
    }
}

static void ausgeben_benotet(int note)
{
    if (ist_spo_note(note))
    {
        printf("%d,%d", note / 10, note % 10);
    }
    else
    {
        printf("Fehler: %d", note);
    }
}

void ausgeben(leistung leistung[])
{
    if (ist_ain2_modul(leistung->modulname))
    {
        printf("%-*s\t", MODULNAME_LENGTH, leistung->modulname);

        if (leistung->leistungsart == unbenotet)
        {
            printf("S\t");
            ausgeben_unbenotet(leistung->status);
        }
        if (leistung->leistungsart == benotet)
        {
            printf("L\t");
            ausgeben_benotet(leistung->note);
        }

        printf("\n");
    }
    else
    {
        printf("Fehler: %-*s\n", MODULNAME_LENGTH, leistung->modulname);
    }
}