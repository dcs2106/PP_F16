all:pi.o single.o
pi.o:
	gcc pi.c -o pi -lpthread
single.o:
	gcc single.c -o single
