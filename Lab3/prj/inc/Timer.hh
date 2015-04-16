/**
*
\file
Timer.h
*
\brief
Plik zawierający deklaracje klasy Timer służącej do pomiaru różnicy czasów.
*/

#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>
/**
\brief
Klasa do pomiaru różnicy czasów.
*
*
Klasa pozwala na pomiar czasów w danych momentach oraz na zwrócenie czasu,
który upłynał pomiędzy tymi momentami
*/
class Timer {
	private:
		/**
		\brief
		Przechowywanie wartości czasu rozpoczęcia pomiaru.
		*/
		std::clock_t _time_start;

		/**
		\brief
		Przechowywanie wartości czasu zakończenia pomiaru.
		*/
		std::clock_t _time_stop;
	public:
		/**
		\brief
		Konstruktor zerujący parametry.
		*
		Konstruktor ten odpowiada za zerowania zmięnnych startu i stopu w celu możliwości późniejszego
		sprawdzenia, czy pomiary czasu konieczne do wyznaczenia różnicy zostały zrealizowane.
		*/
		Timer();

		/**
		\brief
		Zmierzenie czasu rozpoczęcia pomiaru.
		*
		Funkcja zapamiętuje bierzący czas, jako czas rozpoczęcia pomiaru.
		*/
		void startTimer();

		/**
		\brief
		Zmierzenie czasu zakończenia pomiaru.
		*
		Funkcja zapamiętuje bierzący czas, jako czas zakończenia pomiaru.
		*/
		void stopTimer();

		/**
		\brief
		Funkcja zwracająca różnice czasu pomiędzy czasem rozpoczęcia i zakończenia pomiaru.
		*
		Różnica czasu zwracana jest w milisekundach.
		*
		\pre Czas zkończenia pomiaru musi być większy (późniejszy) od czasu jego rozpoczęcia
		*
		\return Zwracana jest różnica czasu zrzutowana do typu double
		*/
		double diffTimeMs();
};


/*test*/


#endif /* TIMER_H_ */
