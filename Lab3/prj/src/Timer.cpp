/**
*
\file
Timer.cpp
*
\brief
Plik zawierający definicje funkcji klasy Timer służącej do pomiaru różnicy czasów.
*/
#include "../inc/Timer.hh"
#include <iostream>
Timer::Timer(): _time_start(0), _time_stop(0) {}
void Timer::startTimer() {
_time_start = std::clock();
}
void Timer::stopTimer() {
_time_stop = std::clock();
}
double Timer::diffTimeMs() {
if(_time_stop >= _time_start) {
return (double)(_time_stop - _time_start) / (CLOCKS_PER_SEC/1000);
}
else {
std::cout<<"Przed wywolaniem funkcji diffTimeMs nalezy odczytac czas rozpoczecia i zakonczenia pomiaru \n"
<<"(time_stop < time_start)";
return 0;
}
}
