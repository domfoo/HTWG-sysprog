#ifndef LEISTUNG_H
#define LEISTUNG_H
#include <stdbool.h>

#define MODULNAME_LENGTH 20

enum leistungsart { benotet, unbenotet };

struct leistung
{
    char modulname[MODULNAME_LENGTH + 1];
    enum leistungsart leistungsart;
    union
    {
        int note;
        char status;
    };
};

typedef struct leistung leistung;

bool leistung_einlesen(leistung*);
void ausgeben(leistung[]);
#endif
