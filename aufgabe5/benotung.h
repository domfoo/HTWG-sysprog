/*
 * benotung.h
 *
 * Author: Dominik Bartsch
 * Version: 22.05.2022
 */
#ifndef BENOTUNG_H
#define BENOTUNG_H

class benotung final
{
private:
    int note;

public:
    static const benotung beste;
    static const benotung schlechteste;

    explicit benotung(int);

    int int_value() const;
    bool ist_bestanden() const;

    friend bool operator==(benotung, benotung);
};

#endif