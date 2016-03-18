#include "cherie.h"

//Constructors definitions

Cherie::Cherie (int sta, int thr, int bldr, int fed){
	Stamina = sta;
	ThirstLevel = thr;
	BladderLevel = bldr;
	FedLevel = fed;
	Locus = annas_room;
}

Cherie::Cherie (){
	Stamina = 5;
	ThirstLevel = 0;
	BladderLevel = 0;
	FedLevel = 2;
	Locus = annas_room;
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

void Cherie::PissAllOver(){
	BladderLevel = 0;
	return ;
}

//ADD and SUBTRACT functions definitions

void Cherie::Staminapp(){
	Stamina++;
	return ;
}

void Cherie::ThirstLevelpp(){
	ThirstLevel++;
	return ;
}

void Cherie::BladderLevelpp(){
	BladderLevel++;
	return ;
}

void Cherie::FedLevelpp(){
	FedLevel++;
	return ;
}

void Cherie::Staminamm(){
	Stamina--;
	return ;
}

void Cherie::ThirstLevelmm(){
	ThirstLevel--;
	return ;
}

void Cherie::BladderLevelmm(){
	BladderLevel--;
	return ;
}

void Cherie::FedLevelmm(){
	FedLevel++;
	return ;
}



