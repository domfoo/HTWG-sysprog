/*
 * fachnote.cpp
 *
 * Autor: Dominik Bartsch
 * Version: 25.05.2022
 */
#include "fachnote.h"
#include "benotung.h"
#include <stdexcept>
#include <string>

fachnote::fachnote(const std::string &fach, const benotung &note)
    : fach(fach), note(note)
{
    if (fach.length() == 0)
    {
        throw std::invalid_argument("Fachname darf nicht leer sein");
    }
}