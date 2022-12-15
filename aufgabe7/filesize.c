/*
 * filesize.c
 *
 * Author: Dominik Bartsch
 * Erstellt am: 25.06.2022
 */
#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <inttypes.h>
#include <unistd.h>
#include <locale.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc == 1)
    {
        uintmax_t anzahl = 0;
        int n;
        unsigned char byte;
        while ((n = read(STDIN_FILENO, &byte, 1)) > 0)
        {
            anzahl += 1;
        }
        if (n < 0)
        {
            fprintf(stderr, "Lesefehler (errno %d: %s)\n", errno, strerror(errno));
            return 1;
        }
        printf("\nStandardeingabe: %ju Byte\n", anzahl);
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            struct stat sb;
            int in = open(argv[i], O_RDONLY);
            if (in == -1)
            {
                fprintf(stderr,
                        "Quelle %s kann nicht geoeffnet werden (errno %d: %s)\n",
                        argv[1], errno, strerror(errno));
                continue;
            }

            if (stat(argv[i], &sb) == -1)
            {
                fprintf(stderr, "Lesefehler %s (errno %d: %s)\n", argv[i], errno, strerror(errno));
                continue;
            }
            printf("%s: %ju bytes\n", argv[i], (uintmax_t) sb.st_size);
            close(in);
        }
    }

    return 0;
}
