#
# Makefile
#
# Autor: Dominik Bartsch
# Erstellt am: 25.06.2022
#

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -Wvla -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11

filesize: filesize.c
	$(CC) $(CFLAGS) filesize.c -o filesize

filecopy: filecopy.c
	$(CC) $(CFLAGS) filecopy.c -o filecopy

clean:
	$(RM) filesize filecopy filesize.o filecopy.o

cppcheck: filesize.c filecopy.c
	$(CPPCHECK) $<
