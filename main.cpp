#include <iostream>
#include <unistd.h>

#include "cherie.h"
#include "cherieStates.h"

#ifndef RANDOM
#define RANDOM_NUM ((float)rand()/(RAND_MAX+1.0))
#endif

using namespace std;

int main (){
	Cherie cherie1(2,2,3,4);
	Cherie* pCherie = &cherie1;
	for(int i =0; i<20;++i){
		cherie1.Update();
		cout << cherie1.GetLocus() << endl << endl ; 
	}
	cout << cherie1.GetStamina() << endl ; 
	return 0;
}