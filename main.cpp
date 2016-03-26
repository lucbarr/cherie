#include "cherieStates.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cherie.h"
#include "loci.h"
#include <unistd.h>

#ifndef RANDOM
#define RANDOM_NUM ((float)rand()/(RAND_MAX+1.0))
#endif

using namespace std;

int main (){
	int hours;
	srand(int(time(NULL)));
	Cherie cherie1(3,4,3,6);
	cout << "Input the number of hours you want to watch Cherie by:" << endl;
	cin >> hours;
	for(int i =0; i<hours*2;++i){
		cherie1.Update();
	}
	return 0;
}