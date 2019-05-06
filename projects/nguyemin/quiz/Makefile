CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)
	./testme

testresults: 
	gcov -fb testme.c

clean:
	rm -f testme *.gcov *.gcda *.gcno