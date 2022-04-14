default : litSerie

litSerie : litSerie.o libSerie.o
	cc -o test litSerie.o libSerie.o

test.o : litSerie.c libSerie.h
	cc -c litSerie.c

libSerie.o : libSerie.c libSerie.h
	cc -c libSerie.c

clean :
	rm -f test *.o
