/*
 * fachnoten_liste.cpp
 *
 * Autor: Dominik Bartsch
 * Version: 25.05.2022
 */
#ifndef FACHNOTEN_LISTE_H
#define FACHNOTEN_LISTE_H

#include "fachnote.h"
class fachnoten_liste final
{
private:
    class element;
    element *head;
    void (*fn) (fachnote*); // Variable für Funktionsadresse

public:
    explicit fachnoten_liste(void (*)(fachnote *f));
    ~fachnoten_liste();

    fachnoten_liste(const fachnoten_liste&) = delete;
    fachnoten_liste(fachnoten_liste&&) = delete;
    fachnoten_liste& operator=(const fachnoten_liste&) = delete;
    fachnoten_liste& operator=(fachnoten_liste&&) = delete;

    fachnoten_liste& insert(fachnote *);

    class iterator final
    {
    private:
        element *current;
        explicit iterator(element*);

    public:
        bool operator!=(const iterator&) const;
        fachnote* operator*() const;
        iterator& operator++();

        friend class fachnoten_liste;
    };

    iterator begin();
    iterator end();
};

#endif