# bin/Makefile

CPPFLAGS = -I ../lib -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic
LDFLAGS = -L../lib -laufgabe6

OBJECTS = \
	notenspiegel.o
SOURCES = $(OBJECTS:.o=.cpp)

TARGET = notenspiegel

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).o $(OBJECTS)
	g++ -c $(CPPFLAGS) $(SOURCES)
	g++ -g $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET) depend

depend: $(SOURCES) $(HEADERS)
	g++ -g $(CPPFLAGS) -MM $(SOURCES) > $@

include depend
