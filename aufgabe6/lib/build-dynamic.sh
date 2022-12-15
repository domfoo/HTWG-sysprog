#! /usr/bin/sh
for s in benotung fachnote fachnoten_liste ; do
  command="g++ -fpic -g -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -c -o $s.o $s.cpp"
  echo $command
  eval $command
  if [ $? -ne 0 ] ; then # Fehlerbehandlung
    echo build failed
    exit 1
  fi
done

g++ --shared benotung.o fachnote.o fachnoten_liste.o -o libaufgabe6.so
if [ $? -ne 0 ] ; then
  echo failed to create dynamic library
  exit 1
fi
