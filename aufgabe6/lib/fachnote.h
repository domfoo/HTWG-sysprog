/*
 * fachnote.h
 *
 * Autor: Dominik Bartsch
 * Version: 25.05.2022
 */
#ifndef FACHNOTE_H
#define FACHNOTE_H

#include <string>
#include "benotung.h"

class fachnote final
{
public:
    const std::string fach;
    const benotung note;

    fachnote(const std::string&, const benotung&);

    //~fachnote() = default;

    fachnote(const fachnote&) = delete;
    fachnote(fachnote&&) = delete;
    fachnote& operator=(const fachnote&) = delete;
    fachnote& operator=(fachnote&) = delete;
};

#endif