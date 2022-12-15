/*
 * aufgabe1.c
 *
 * Programm für die erste Aufgabe.
 *
 * Author: Dominik Bartsch
 * Datum: 28.03.2022
 */

#include <stdio.h>
#include <stdbool.h>
//#include <string.h>

int main(void)
{
    // ganze Zahlen
    int zahl1 = 128;
    short int zahl2 = 23;
    long int zahl3 = 4532;
    long long int zahl4 = 2354;
    unsigned int zahl5 = 128;
    unsigned short int zahl6 = 23;
    unsigned long int zahl7 = 4532;
    unsigned long long int zahl8 = 2354;

    // Kommazahlen
    float kommazahl1 = 12.5;
    double kommazahl2 = 15.6;
    long double kommazahl3 = 2.5;

    // Zeichen
    char zeichen = 'D';
    signed char byte1 = -1;
    unsigned char byte2 = 0x4f;

    // Boolesche Variable
    bool ja = true;

    // Zeiger auf das erste Element eines Strings
    const char* s = "Hallo";

    // Tabelle mit Addresse, Platzbedarf, Typ, Name und Wert der Variablen ausgeben
    printf("ADDRESS \t| SIZE \t| TYPE \t\t\t\t| NAME \t\t| VALUE\n");

    // ganze Zahle ausgeben
    printf("%p \t| %zu \t| int \t\t\t\t| zahl1 \t| %d\n", (void*) &zahl1, sizeof zahl1, zahl1);
    printf("%p \t| %zu \t| short int \t\t\t| zahl2 \t| %hd\n", (void*) &zahl2, sizeof zahl2, zahl2);
    printf("%p \t| %zu \t| long int \t\t\t| zahl3 \t| %ld\n", (void*) &zahl3, sizeof zahl3, zahl3);
    printf("%p \t| %zu \t| long long int \t\t| zahl4 \t| %lld\n", (void*) &zahl4, sizeof zahl4, zahl4);
    printf("%p \t| %zu \t| unsigned int \t\t\t| zahl5 \t| %u\n", (void*) &zahl5, sizeof zahl5, zahl5);
    printf("%p \t| %zu \t| unsigned short int \t\t| zahl6 \t| %hu\n", (void*) &zahl6, sizeof zahl6, zahl6);
    printf("%p \t| %zu \t| unsigned long int \t\t| zahl7 \t| %lu\n", (void*) &zahl7, sizeof zahl7, zahl7);
    printf("%p \t| %zu \t| unsigned long long int \t| zahl8 \t| %llu\n", (void*) &zahl8, sizeof zahl8, zahl8);

    // Kommazahlen ausgeben
    printf("%p \t| %zu \t| float \t\t\t| kommazahl1 \t| %f\n", (void*) &kommazahl1, sizeof kommazahl1, kommazahl1);
    printf("%p \t| %zu \t| double \t\t\t| kommazahl2 \t| %f\n", (void*) &kommazahl2, sizeof kommazahl2, kommazahl2);
    printf("%p \t| %zu \t| long double \t\t\t| kommazahl3 \t| %Lf\n", (void*) &kommazahl3, sizeof kommazahl3, kommazahl3);

    // Zeichen ausgeben
    printf("%p \t| %zu \t| char \t\t\t\t| zeichen \t| %c\n", (void*) &zeichen, sizeof zeichen, zeichen);
    printf("%p \t| %zu \t| signed char \t\t\t| byte1 \t| %hhd\n", (void*) &byte1, sizeof byte1, byte1);
    printf("%p \t| %zu \t| unsigned char \t\t| byte2 \t| 0x%hhx\n", (void*) &byte2, sizeof byte2, byte2);

    // Boolesche Variable ausgeben
    printf("%p \t| %zu \t| bool \t\t\t\t| ja \t\t| %d\n", (void*) &ja, sizeof ja, ja);

    // String ausgeben
    printf("%p \t| %zu \t| const char* \t\t\t| s \t\t| %p\n", (void*) &s, sizeof s, s);

    // Ausgeben, welches C-Datenmodell benutzt wird
    int sizeint = sizeof (int);
    int sizelong = sizeof (long int);
    int sizell = sizeof (long long int);
    int sizeptr = sizeof (char*);

    if (sizelong == 4 && sizeint == 4 && sizeptr == 4)
    {
        printf("\nDieses System nutzt das ILP32-Datenmodell.\n");
    }
    else if (sizelong == 8 && sizeint == 4 && sizeptr == 8)
    {
        printf("\nDieses System nutzt das LP64-Datenmodell.\n");
    }
    else if (sizelong == 4 && sizeint == 4 && sizell == 8 && sizeptr == 8)
    {
        printf("\nDieses System nutzt das LLP64-Datenmodell.\n");
    }
    else 
    {
        printf("\n Dieses System nutzt ein unbekanntes Datenmodell.\n");
    }

    return 0;
}