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

/*//////////////////////////////////////////////////////////////////////////////
//////////////////////// file : main.cpp ///////////////////////////////////////
	description:
		The main function basically holds the finite state machine loop,
	calling Update method. This method calls the Run method from Cherie class
	cherie1's current state. In this method, the state might be changed or not.
	If it is, the ChangeState method from Cherie class will call the Exit
	method from current state, change the current state to the new state then
	call the Enter method from the new state. Then Update is called again,
	repeating the whole process, now with the new state as the actual current 
	state.
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////*/


int main (){
	char c;
	int hours;
	srand(int(time(NULL)));
	Cherie cherie1(3,4,3,6);
	cout << "Input the number of hours you want to watch Cherie by:" << endl;
	cin >> hours;
	for(int i =0; i<hours*2;++i){
		cherie1.Update();
	}
	cout << "Press any key to exit." << endl;
	cin >> c;
	return 0;
}