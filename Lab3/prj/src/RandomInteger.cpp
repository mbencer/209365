/*
 * RandomInteger.cpp
 *
 *  Created on: 09-04-2015
 *      Author: mateusz
 */

#include "RandomInteger.h"
#include <cstdlib>
#include <time.h>

RandomInteger::RandomInteger(int max) {
	_max=max;
	srand((unsigned)time(NULL));

}

int RandomInteger::rand() {
	return (rand()%_max);

}


