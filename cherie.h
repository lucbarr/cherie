#ifndef CHERIE_H
#define CHERIE_H 
#include "loci.h"
#include "cherieStates.h"

/*
Header file for the sake of Cherie class definition.
Here we define its methods, constants, and constructors,
basically.
*/

const int FedThresold = 4;
const int ThirstThreshold = 5;
const int TiredThreshold = 6;
const int FullBladder = 4;
const float ScratchChance = 0.90f;

class Cherie{
	private:
		loci Locus;
		int Stamina;
		int ThirstLevel;
		int BladderLevel;
		int FedLevel;
	public:
		Cherie(int, int, int, int);
		Cherie ();

		bool IsTired();
		bool IsBladderFull();
		bool IsThirsty();
		bool IsFed();

		void ChangeLocus(loci newLocus);

		void PissAllOver();
		//pp functions sums 1 to variables
		void Staminapp(int val);
		void ThirstLevelpp(int val);
		void BladderLevelpp(int val);
		void FedLevelpp(int val);

		int GetStamina(){return Stamina;}
		int GetThirstLevel(){return ThirstLevel;}
		int GetBladderLevel(){return BladderLevel;}
		int GetFedLevel(){return FedLevel;}
		loci GetLocus(){return Locus;}

};

#endif