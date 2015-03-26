#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Benchmark
	./Benchmark

Benchmark: obj/Test.o obj/Benchmark.o
	g++ -Wall -pedantic -o Benchmark obj/Test.o obj/Benchmark.o 

obj/Test.o: src/Test.cpp inc/Benchmark.hh inc/Lista.hh inc/Kolejka.hh inc/Stos.hh 
	g++ ${CPPFLAGS} -o obj/Test.o src/Test.cpp


obj/Benchmark.o: src/Benchmark.cpp inc/Benchmark.hh 
	g++ ${CPPFLAGS} -o obj/Benchmark.o src/Benchmark.cpp

Struktury: obj/Struktury.o
	g++ -Wall -pedantic -o Struktury obj/Struktury.o 

obj/Struktury.o: src/Struktury.cpp inc/Element.hh inc/Lista.hh inc/Kolejka.hh inc/Stos.hh
	g++ ${CPPFLAGS} -o obj/Struktury.o src/Struktury.cpp


clean:
	rm -f obj/*.o Struktury Test
