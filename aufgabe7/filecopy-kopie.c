/*
 * filecopy.c
 *
 * Author Dominik Bartsch
 * Erstellt am: 25.06.2022
 */

#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (setlocale(LC_MESSAGES, "de_DE.UTF-8") == NULL)
    {
        fprintf(stderr, "Platform unterstützt keine deutschen Systemmeldungen\n");
    }

    if (argc != 3)
    {
        fprintf(stderr, "Aufruf: %s Quelle Ziel\n", argv[0]);
        return 1;
    }

    struct stat src_stat;
    int return_val = 0;
    
    int src = open(argv[1], O_RDONLY);
    if (src == -1)
    {
        perror("open()");
        return 1;
    }

    if (fstat(src, &src_stat) != 0)
    {
        perror("fstat()");
        return 1;
    }

    // Zieldatei erstellen oder eine Vorhandene benutzen
    int dst = creat(argv[2], src_stat.st_mode);
    if (dst == -1)
    {
        perror("creat()");
        return 1;
    }

    unsigned char *buff = malloc(src_stat.st_size);
    if (buff == NULL)
    {
        if (buff == NULL)
        {
            fprintf(stderr, "malloc(): failed");
            return_val = 1;
        }
    }

    ssize_t size = read(src, buff, src_stat.st_size);

    if (size == -1)
    {
        perror("read()");
        return_val = 1;
    }

    if(size < src_stat.st_size) {
        fprintf(stderr, "Smaller than Bytes requested\n");
        return_val = 1;
    }

    ssize_t bytes_written;
    if ((bytes_written = write(dst, buff, (size_t)size)) == -1)
    {
        perror("write()");
        return_val = 1;
    }

    if(bytes_written < src_stat.st_size) {
        fprintf(stderr, "Smaller than Bytes requested\n");
        return_val = 1;
    }

    free(buff);
    close(src);
    close(dst);
       
    return return_val;
}
