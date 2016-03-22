#include <iostream>
#include <unistd.h>

#include "cherie.h"

#ifndef RANDOM
#define RANDOM_NUM ((float)rand()/(RAND_MAX+1.0))
#endif

using namespace std;

int main (){
	Cherie cherie1(2,2,3,4);

	cout << cherie1.GetThirstLevel() << endl;
	cherie1.ThirstLevelpp(2);
	cout << cherie1.GetThirstLevel() << endl << cherie1.IsThirsty() << endl;

	return 0;
}