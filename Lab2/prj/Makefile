#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Struktury
	./Struktury

Struktury: obj/Lista.o
	g++ -Wall -pedantic -o Struktury obj/Lista.o 

obj/Lista.o: src/Lista.cpp inc/Lista.hh 
	g++ ${CPPFLAGS} -o obj/Lista.o src/Lista.cpp


clean:
	rm -f obj/*.o Benchmark
