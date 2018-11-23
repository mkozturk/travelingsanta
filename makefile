all : data.c santa.h libsanta.so test

data.c santa.h : prepdata.py cities.csv
	python prepdata.py

libsanta.so : data.c santa.c santa.h
	gcc -c -fPIC data.c santa.c -lm
	gcc -shared data.o santa.o -o libsanta.so -lm

test : main.c data.c santa.c
	gcc -L. -Wall -lsanta main.c -o test

clean :
	rm data.c santa.h libsanta.so test
