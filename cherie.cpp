#include "cherie.h"
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cherieStates.h"

#ifndef RANDOM
#define RANDOM_NUM ((float)rand()/(RAND_MAX+1.0))
#endif

//Methods definition cpp file

//Constructors definitions

Cherie::Cherie (int sta, int thr, int bldr, int fed){
	Stamina = sta;
	ThirstLevel = thr;
	BladderLevel = bldr;
	FedLevel = fed;
	Locus = annas_room;
	Time = 6;
	currentState = Lain::Instance();
}

Cherie::Cherie (){
	Stamina = 5;
	ThirstLevel = 0;
	BladderLevel = 0;
	FedLevel = 2;
	Locus = annas_room;
	Time = 6;
}

void Cherie::ChangeState(State* newState){
	assert(newState && currentState);

	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}

void Cherie::TimeUpdate(){
	Time++;
	if (Time>=24){
		Time=Time-24;
	}
}

void Cherie::ShowTime(){
	std::cout << "( " << Time << " : " << (int)RANDOM_NUM*60 <<" )";
}

//Boolean status functions definitions

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
	if (Time<=13 && Time>=11){
		return true;
	}
	else if (Time<=20 && Time>=18){
		return true;
	}
	else if (Time<=8 && Time>=6){
		return true;
	}
	else{
		return false;
	}
}

void Cherie::ChangeLocus(loci newLocus){
	Locus = newLocus;
	return ;
}

void Cherie::PissAllOver(){
	BladderLevel = 0;
	return ;
}

//ADD and SUBTRACT functions definitions

void Cherie::Staminapp(int val){
	Stamina+=val;
	if (Stamina<0)
		Stamina = 0;
	return ;
}

void Cherie::ThirstLevelpp(int val){
	ThirstLevel+=val;
	if (ThirstLevel<0)
		ThirstLevel = 0;
	return ;
}

void Cherie::BladderLevelpp(int val){
	BladderLevel+=val;
	if (BladderLevel<0)
		BladderLevel = 0;
	return ;
}

void Cherie::FedLevelpp(int val){
	FedLevel+=val;
	if (FedLevel<0)
		FedLevel = 0;
	return ;
}