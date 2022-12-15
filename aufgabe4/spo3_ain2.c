#include "spo3_ain2.h"

#include <stdbool.h>
#include <string.h>

// prüft, ob die Note nach SPO3 für AIN2 zulässig ist
bool ist_spo_note(int note) {
    switch (note) {
        case 10:
        case 13:
        case 17:
        case 20:
        case 23:
        case 27:
        case 30:
        case 33:
        case 37:
        case 40:
        case 50:
            return true;
        default:
            return false;
    }
}

// prüft, ob das Modul nach SPO3 für AIN2 zulässig ist
bool ist_ain2_modul(const char *modul) 
{
    if (
        strcmp(modul, "Systemprogrammierung") == 0
        || strcmp(modul, "Rechnerarchitekturen") == 0
        || strcmp(modul, "Programmiertechnik 2") == 0
        || strcmp(modul, "Mathematik 2") == 0
        || strcmp(modul, "Stochastik") == 0) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}