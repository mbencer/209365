#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Benchmark
	./Benchmark

Benchmark: obj/main.o obj/Benchmark.o
	g++ -Wall -pedantic -o Benchmark obj/main.o obj/Benchmark.o 

obj/main.o: src/main.cpp inc/Benchmark.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp


obj/Benchmark.o: src/Benchmark.cpp inc/Benchmark.hh 
	g++ ${CPPFLAGS} -o obj/Benchmark.o src/Benchmark.cpp


clean:
	rm -f obj/*.o Benchmark
