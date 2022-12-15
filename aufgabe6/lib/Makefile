# lib/Makefile

CPPFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic

LIBTYPE = a
LIBNAME = aufgabe6
LIB_NAMES = \
	lib$(LIBNAME).a \
	lib$(LIBNAME).so
OBJECTS = \
    benotung.o \
    fachnote.o \
    fachnoten_liste.o
BUILD_STATIC = ar rvs lib$(LIBNAME).$(LIBTYPE) $(OBJECTS)
BUILD_DYNAMIC = g++ -shared -fPIC $(OBJECTS:.o=.cpp) -o lib$(LIBNAME).$(LIBTYPE)

SOURCES = $(OBJECTS:.o=.cpp)
HEADERS = $(OBJECTS:.o=.h)

.PHONY: all clean

all: lib$(LIBNAME).$(LIBTYPE)

lib$(LIBNAME).a:
	g++ -c $(CPPFLAGS) $(SOURCES)
	$(BUILD_STATIC)

lib$(LIBNAME).so:
	$(BUILD_DYNAMIC)

clean:
	rm -f $(OBJECTS) $(LIB_NAMES) depend

depend: $(SOURCES) $(HEADERS)
	g++ -c $(CPPFLAGS) -MM $(SOURCES) > $@

include depend