#ifndef ELEMENT_HH
#define ELEMENT_HH
/*!
 *\file
 *\brief Definicja klasy Element
 *
 * Plik zawiera definicje klasy Element, ktora bedzie
 * pojedynczym elementem naszej struktury.
 * Klasa ta posiada szablon, dzieki czemu mozemy pracowac na 
 * roznych typach danych
 */


/*!
 * \brief Klasa Element
 *
 * Klasa ta modeluje nam pojedyncza dana oraz wskaznik na kolejna dana
 * \param[in] *nastepny - jako wskaznik na kolejny element
 * \param[in] wartosc - wartosc naszego elementu zdefiniowana przez nas przy uzyciu szablonu
 */
template<class TYP>
class Element
{
	
public:
	TYP wartosc;
	Element *nastepny;

Element()
{
  nastepny=NULL;
}

~Element()
{
}
};

#endif
