#ifndef CHERIE_H
#define CHERIE_H 
#include "loci.h"
#include "cherieStates.h"

/*///////////////////////////////////////////////////////////////////
//////////////////////// file : cherie.h ////////////////////////////
	description:
		Header file for the sake of Cherie class definition.
	Here we define its methods, constants and constructors,
	basically.
/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////*/

class State;

const int FedThresold = 4;
const int ThirstThreshold = 4;
const int TiredThreshold = 3;
const int RestedThreshold = 9;
const int FullBladder = 5;

/* Chances of things happening. Totally arbitrary */

const float ScratchingC = 0.90f;
const float GetHungryWhileSleepingC = 0.70f;
const float GetThirstyWhileSleepingC = 0.60f;
const float ExtraStaminaC = 0.40f;
const float ExtraFatigueC = 0.35f;
const float ExtraThirstC = 0.30f;
const float ExtraFedLevelC = 0.5f;

class Cherie{
	private:
		State* currentState;
		loci Locus;
		int Stamina;
		int ThirstLevel;
		int BladderLevel;
		int FedLevel;
		int Time;
	public:
		Cherie(int, int, int, int);
		Cherie();

		void Update();

		bool IsTired();
		bool IsBladderFull();
		bool IsThirsty();
		bool IsFed();
		bool IsBeggingTime();
		bool IsRested();

		void ChangeLocus(loci newLocus);
		void ChangeState(State* newState);
		void TimeUpdate();
		void ShowTime();

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

		void PrintStatus();

		State* GetCurrentState(){return currentState;} //debugging funct
};

#endif