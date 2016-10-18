all:pi.o single.o
pi.o:
	gcc pi.c -o pi -lpthread -O2
single.o:
	gcc single.c -o single
