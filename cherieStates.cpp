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

/////////////////////////////////////////////////////////////////////////////////////////////////////

Lain* Lain::Instance(){
	static Lain instance;
	return &instance;
}

void Lain::Enter(Cherie* pCherie){
	sleep(2);
	if ((pCherie->GetLocus() != annas_room)){ // todo add change to diag
		cout << " *yawning* Cherie heads towards Anna's room " << endl;
		pCherie->ChangeLocus(annas_room);
	}
}

void Lain::Run(Cherie* pCherie){
	sleep(2);
	srand(int(time(NULL)));
	pCherie->Staminapp(1);
	if (RANDOM_NUM < ExtraStaminaC){pCherie->Staminapp(1);}
	if (RANDOM_NUM < GetHungryWhileSleepingC){pCherie->FedLevelpp(-1);}
	if (RANDOM_NUM < GetThirstyWhileSleepingC){pCherie->ThirstLevelpp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << " *zzZzZz* Cherie is lain down sleeping like an angel... dog" << endl;
	if (!pCherie->IsRested()){

	}
	else if (pCherie->IsBladderFull()){
		pCherie->ChangeState(Pissing::Instance());
	}
	else if (!pCherie->IsFed()){
		pCherie->ChangeState(Eating::Instance());
	}
	else if (pCherie->IsBeggingTime()){
		pCherie->ChangeState(Begging::Instance());
	}
	else {
		pCherie->ChangeState(Scratching::Instance());
	}

	return ;
}

void Lain::Exit(Cherie* pCherie){
	sleep(2);
	pCherie->ShowTime();
	cout << " *dog moaning* Cherie is waking up!! Prepare yourselves!!" << endl;
	return ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Pissing* Pissing::Instance(){
	static Pissing instance;
	return &instance;
}

void Pissing::Enter(Cherie* pCherie){
	sleep(2);
	if ((pCherie->GetLocus() != living_room)){
		pCherie->ShowTime();
		cout << " *Woof Woof!* Cherie is heading the living room ready to land a load!!!" << endl;
		pCherie->ChangeLocus(living_room);
	}
	return ;
}

void Pissing::Run(Cherie* pCherie){
	sleep(2);
	srand(int(time(NULL)));
	pCherie->PissAllOver();
	if(RANDOM_NUM < ExtraThirstC){pCherie->ThirstLevelpp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << " *pshhhshshshhhs* Oh no!! Cherie pissed all over the living room's floor!!" << endl;
	if (!pCherie->IsFed()){
		pCherie->ChangeState(Eating::Instance());
	}
	else if (pCherie->IsThirsty()){
		pCherie->ChangeState(Drinking::Instance());
	}
	else if (pCherie->IsBeggingTime()){
		pCherie->ChangeState(Begging::Instance());
	}
	else {
		pCherie->ChangeState(Scratching::Instance());
	}
	return ;
}

void Pissing::Exit(Cherie* pCherie){
	sleep(2);
	pCherie->ShowTime();
	cout << " Cherie sashays away from the living room as if nothing happened" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Eating* Eating::Instance(){
	static Eating instance;
	return &instance;
}

void Eating::Enter(Cherie* pCherie){
	sleep(2);
	if(pCherie->GetLocus()!=bowls_room){
		pCherie->ShowTime();
		cout << " *sound of a HUNGRY dogue* Cherie enters bowls' room" << endl;
		pCherie->ChangeLocus(bowls_room);
	}
	return ;
}

void Eating::Run (Cherie* pCherie){
	sleep(2);
	srand(int(time(NULL)));
	pCherie->FedLevelpp(2);
	if (RANDOM_NUM > ExtraFedLevelC){pCherie->FedLevelpp(1);}
	if (RANDOM_NUM > ExtraStaminaC){pCherie->Staminapp(1);}
	if (RANDOM_NUM > ExtraThirstC){pCherie->ThirstLevelpp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << " *sound of a dog eating* Cherie eats like a doge !!" << endl;
	if (!pCherie->IsFed()){
		
	}
	else if (pCherie->IsThirsty()){
		pCherie->ChangeState(Drinking::Instance());
		sleep(2);
		pCherie->ShowTime();
		cout << " Cherie aims the other bowl" << endl;
	}
	else if (pCherie->IsTired()){
		pCherie->ChangeState(Lain::Instance());
	}
	else if (RANDOM_NUM < ScratchingC){
		pCherie->ChangeState(Scratching::Instance());
	}
	return ;
}

void Eating::Exit (Cherie* pCherie){
	sleep(2);
	pCherie->ShowTime();
	cout << " *Woof woof!* Cherie is done eating like a doge" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Drinking* Drinking::Instance(){
	static Drinking instance;
	return &instance;
}

void Drinking::Enter(Cherie* pCherie){
	sleep(2);
	if((pCherie->GetLocus()!=bowls_room)){
		pCherie->ShowTime();
		cout << " *puffy dog sound* Cherie needs water, she ramparts towards bowls room" << endl;
		pCherie->ChangeLocus(bowls_room);
	}
	return ;
}

void Drinking::Run (Cherie* pCherie){
	sleep(2);
	srand(int(time(NULL)));
	pCherie->ThirstLevelpp(-3);
	pCherie->BladderLevelpp(2);
	if (RANDOM_NUM < 0.2f){pCherie->Staminapp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << " *sound of a dog drinking* Cherie is drinking water like a dog" << endl;
	if (pCherie->IsThirsty()){
		
	}
	else if (pCherie->IsBladderFull()){
		pCherie->ChangeState(Pissing::Instance());
	}
	else if (pCherie->IsFed()){
		pCherie->ShowTime();
		cout << " Cherie aims the other bowl" << endl;
		pCherie->ChangeState(Eating::Instance());
	}
	else {
		pCherie->ChangeState(Scratching::Instance());
	}
	return ;
}

void Drinking::Exit(Cherie* pCherie){
	sleep(2);
	pCherie->ShowTime();
	cout << " *spills water allover* Cherie is done fericiously drinking water" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Scratching* Scratching::Instance(){
	static Scratching instance;
	return &instance;
}

void Scratching::Enter(Cherie* pCherie){
	sleep(2);
	if(pCherie->GetLocus()!= annas_room){
		pCherie->ShowTime();
		cout << " *dog paws shaking* After feeling an urge to scratch herself, Cherie enters Anna's room" << endl;
		pCherie->ChangeLocus(annas_room);
	}
}

void Scratching::Run(Cherie* pCherie){
	sleep(2);
	srand(int(time(NULL)));
	pCherie->Staminapp(-1);
	if (RANDOM_NUM < ExtraStaminaC){pCherie->Staminapp(-1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << " *KaPOW!* Cherie ferociously swipes her paws into her own fur" << endl;
	if(pCherie->IsTired()){
		pCherie->ChangeState(Lain::Instance());
	}
	else if (pCherie->IsThirsty()){
		pCherie->ChangeState(Drinking::Instance());
	}
	else if (pCherie->IsBladderFull()){
		pCherie->ChangeState(Pissing::Instance());
	}
	else if (!pCherie->IsFed()){
		pCherie->ChangeState(Eating::Instance());
	}
	else if (pCherie->IsBeggingTime()){
		pCherie->ChangeState(Begging::Instance());		
	}
}

void Scratching::Exit(Cherie* pCherie){
	sleep(2);
	pCherie->ShowTime();
	cout << " *satisfaction sigh* Cherie is done pleasing her scratching urges" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Begging* Begging::Instance(){
	static Begging instance;
	return &instance;
}

void Begging::Enter(Cherie* pCherie){
	sleep(2);
	if(pCherie->GetLocus()!=dining_room){
		pCherie->ShowTime();
		cout << " *Whining* Cherie can smell the food from far... (heads towards dining room)" << endl;
		pCherie->ChangeLocus(dining_room);
	}
	return ;
}

void Begging::Run(Cherie* pCherie){
	sleep(2);
	srand(int(time(NULL)));
	pCherie->Staminapp(-1);
	if (RANDOM_NUM < ExtraThirstC){pCherie->ThirstLevelpp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	if (RANDOM_NUM < 0.5f){
		cout << " 'There it is, Cherie' *Cherie grabs thrown food midair*" << endl;
		pCherie->ChangeState(Eating::Instance());
	}
	else {
		cout << " 'Bad dog!! No food for you!!'" << endl;
		if (pCherie->IsBladderFull()){
			pCherie->ChangeState(Pissing::Instance());
			cout << " OOoh no, Cherie, not again!!" << endl;
		}
		else if (!(pCherie->IsFed())){
			pCherie->ChangeState(Eating::Instance());
		}
		else {
			if(pCherie->IsBeggingTime()){
				
			}
			else {
				pCherie->ChangeState(Scratching::Instance());
			}
		}
	}
	return ;
}

void Begging::Exit(Cherie* pCherie){
	sleep(2);
	pCherie->ShowTime();
	cout << " *whining* Looks like Cherie is tired of begging..." << endl ;
	return ;
}