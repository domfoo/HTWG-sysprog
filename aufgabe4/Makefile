#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 30.8.2021
#

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11

TARGET = notenspiegel
OBJECTS = \
    leistung.o \
    spo3_ain2.o \

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

cppcheck: $(TARGET).c $(OBJECTS:.o=.c)
	$(CPPCHECK) $^

leistung.o:leistung.c leistung.h spo3_ain2.h
spo3_ain2.o: spo3_ain2.c spo3_ain2.h
notenspiegel.o: notenspiegel.c leistung.h spo3_ain2.h

