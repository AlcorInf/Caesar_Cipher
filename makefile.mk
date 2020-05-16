a.out: main.o crypter.o
	gcc main.o crypter.o
main.o: main.c crypter.h
	gcc -c main.c
crypter.o: crypter.c crypter.h
	gcc -c crypter.c
