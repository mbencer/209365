CC = g++
#LIBS = -lm
CFLAGS = -Wall -pedantic -Iinc
#-std=c99
OBJ =\
	obj/main.o \
	obj/Lista.o \
	obj/Timer.o

INC = \
	inc/Lista.hh \
	inc/Benchmark.hh \
	inc/Pivot.hh \
	inc/quick_sort.hh


all: obj main


sam_main:  
	$(CC) $(CFLAGS) src/main.cpp -o program

start: obj main
	rm -f *.o obj/*.o; ./program

obj:
	mkdir obj
clean:
	rm -f *.o program obj/*.o

$(OBJ): obj/%.o : src/%.cpp 
	$(CC) -c $(CFLAGS) $< -o $@

main: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o program

kopia:
	rm -f src/*.cpp~ inc/*.cpp~

doxy:
	cd ../dox;  make
