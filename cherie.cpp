#include "cherie.h"

//Methods definition cpp file

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



