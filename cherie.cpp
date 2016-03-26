#include "cherie.h"
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cherieStates.h"


/*///////////////////////////////////////////////////////////////////////
//////////////////////// file : cherie.cpp //////////////////////////////
	description:
		Code file in which is defined each method from Cherie class.
	Here you find methods that can return Cherie's variables, print
	some of them, change them or that can tell wether if she is fed
	or hungry, thirsty or not, rested or not, tired or not et cetera.
/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////*/

#ifndef RANDOM_NUM
#define RANDOM_NUM ((float)rand()/(RAND_MAX+1.0))
#endif

/*///////////////////////////////////////////////////////////////////
//	These are overloaded constructors from Cherie class.
*////////////////////////////////////////////////////////////////////

Cherie::Cherie (int sta, int thr, int bldr, int fed){
	Stamina = sta;
	ThirstLevel = thr;
	BladderLevel = bldr;
	FedLevel = fed;
	Locus = annas_room;
	Time = 12;
	currentState = Lain::Instance();
}

Cherie::Cherie (){
	Stamina = 5; 
	ThirstLevel = 0;
	BladderLevel = 0;
	FedLevel = 2;
	Locus = annas_room;
	Time = 6;
	currentState = Lain::Instance();
}


/*///////////////////////////////////////////////////////////////////
//	ChangeState method takes a State pointer. It exits object's
//current state, changes states to the pointer's state then enters
//this state.
*////////////////////////////////////////////////////////////////////


void Cherie::ChangeState(State* newState){
	assert(newState && currentState);

	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}

/*///////////////////////////////////////////////////////////////////
//	Update method takes no argument. It simply executes the current
//state, in which it may be changed or not. You can see how these
//Run methods are defined in cherieStates.cpp.
*////////////////////////////////////////////////////////////////////


void Cherie::Update(){
	currentState->Run(this);
}

/*///////////////////////////////////////////////////////////////////
//	Time is set to be 48 discrete periods of 30 minutes within a day.
//TimeUpdate sums 1 to Time, heading it to the next period. If it
//passes 48, it wraps Time around for another day.
*////////////////////////////////////////////////////////////////////

void Cherie::TimeUpdate(){ 
	Time++;
	if (Time>=48){
		Time=Time-48;
	}
}

/*///////////////////////////////////////////////////////////////////
//	ShowTime method simply prints the current time.
*////////////////////////////////////////////////////////////////////

void Cherie::ShowTime(){
	if(Time>=0 and Time <=19){
		std::cout << "( " << Time/2 << "  : " << 3*(Time%2) << "0 )";
	}
	else{
		std::cout << "( " << Time/2 << " : " << 3*(Time%2) << "0 )";
	}
}

/*///////////////////////////////////////////////////////////////////
//	Boolean functions tells how Cherie is and if it's begging time.
//Begging time is when people are eating.
*////////////////////////////////////////////////////////////////////

bool Cherie::IsTired(){
	return Stamina < TiredThreshold;
}

bool Cherie::IsBladderFull(){
	return BladderLevel > FullBladder;
}

bool Cherie::IsThirsty(){
	return ThirstLevel > ThirstThreshold;
}

bool Cherie::IsFed(){
	return FedLevel >= FedThresold;
}

bool Cherie::IsBeggingTime(){
	if (Time<=12 && Time>=16){
		return true;
	}
	else if (Time<=26 && Time>=22){
		return true;
	}
	else if (Time<=40 && Time>=36){
		return true;
	}
	else{
		return false;
	}
}

bool Cherie::IsRested(){
	return Stamina>=RestedThreshold;
}

/*//////////////////////////////////////////////////////////////////////
//	ChangeLocus method literally changes where Cherie is in the moment
*///////////////////////////////////////////////////////////////////////

void Cherie::ChangeLocus(loci newLocus){
	Locus = newLocus;
	return ;
}

/*///////////////////////////////////////////////////////////////////
//	These methods are the ones to change variables values. 
//<Variable>pp methods takes an integer and sums its value to the
//Variable itself. Here are set a floor value for the variables,
//which is 0.
*////////////////////////////////////////////////////////////////////

void Cherie::PissAllOver(){
	BladderLevel = 0;
	return ;
}

void Cherie::Staminapp(int val){
	Stamina=Stamina+val;
	if (Stamina<0){
		Stamina = 0;
	}
	return ;
}

void Cherie::ThirstLevelpp(int val){
	ThirstLevel+=val;
	if (ThirstLevel<0){
		ThirstLevel = 0;
	}
	return ;
}

void Cherie::BladderLevelpp(int val){
	BladderLevel+=val;
	if (BladderLevel<0){
		BladderLevel = 0;
	}
	return ;
}

void Cherie::FedLevelpp(int val){
	FedLevel+=val;
	if (FedLevel<0){
		FedLevel = 0;
	}
	return ;
}
/* PrintStatus was merely done for debugging purposes
void Cherie::PrintStatus(){ 
	std::cout << std:: endl << "S: " << Stamina << " F: " << FedLevel << " B: " << BladderLevel << " T: " << ThirstLevel << " L: " << Locus << std::endl ;
}
*/