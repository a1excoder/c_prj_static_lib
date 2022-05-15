build:
	gcc main.c -L./ -lGlearn -o app
	del libGlearn.a

lib:
	gcc -c glearn.c -o glearn.o
	ar rcs libGlearn.a glearn.o
	del glearn.o