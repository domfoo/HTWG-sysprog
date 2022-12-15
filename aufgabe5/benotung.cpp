/*
 * benotung.cpp
 *
 * Author: Dominik Bartsch
 * Version: 22.05.2022
 */
#include "benotung.h"
#include <stdexcept>
#include <string>


// Konstruktor
benotung::benotung(int note)
    : note(note)
{
    switch (note)
    {
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
        break;
    default:
        throw std::invalid_argument("unzulaessige Note " + std::to_string(note));
    }
}

// Bestmoegliche Note
const benotung benotung::beste(10);

// Schlechteste Note
const benotung benotung::schlechteste(50);

int benotung::int_value() const
{
    return this->note;
}

bool benotung::ist_bestanden() const
{
    return this->note <= 40;
}

bool operator==(benotung a, benotung b)
{
    return &a == &b || a.note == b.note;
}
