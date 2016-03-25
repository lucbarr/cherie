#include "cherieStates.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cherie.h"
#include "loci.h"

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
	if ((pCherie->GetLocus() != annas_room) && (pCherie->IsTired())){ // todo add change to diag
		cout << "--> *yawning* Cherie heads towards Anna's room " << endl;
		pCherie->ChangeLocus(annas_room);
	}
}

void Lain::Run(Cherie* pCherie){
	pCherie->Staminapp((int)(2*RANDOM_NUM)+1);
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << "--> *zzZzZz* Cherie is lain down sleeping like an angel... dog" << endl;
	if (pCherie->IsTired()){
		pCherie->ChangeState(Lain::Instance());
	}
	else if (pCherie->IsBladderFull()){
		pCherie->ChangeState(Pissing::Instance());
	}
	else {
		pCherie->ChangeState(Scratching::Instance());
	}

	return ;
}

void Lain::Exit(Cherie* pCherie){
	cout << "--> *dog moaning* Cherie is waking up!! Prepare yourselves!!" << endl;
	return ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Pissing* Pissing::Instance(){
	static Pissing instance;
	return &instance;
}

void Pissing::Enter(Cherie* pCherie){
	if ((pCherie->GetLocus() != living_room) && (pCherie->IsBladderFull())){
		cout << "--> *Woof Woof!* Cherie is heading the living room ready to land a load!!!" << endl;
		pCherie->ChangeLocus(living_room);
	}
	return ;
}

void Pissing::Run(Cherie* pCherie){
	pCherie->PissAllOver();
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << "*pshhhshshshhhs* Oh no!! Cherie pissed all over the living room's floor!!" << endl;
	if (!(pCherie->IsFed())){
		pCherie->ChangeState(Eating::Instance());
	}
	else if (pCherie->IsThirsty()){
		pCherie->ChangeState(Drinking::Instance());
	}
	else {
		pCherie->ChangeState(Scratching::Instance());
	}
	return ;
}

void Pissing::Exit(Cherie* pCherie){
	cout << "--> Cherie sashays away from the living room as if nothing happened" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Eating* Eating::Instance(){
	static Eating instance;
	return &instance;
}

void Eating::Enter(Cherie* pCherie){
	if(pCherie->GetLocus()!=bowls_room){
		cout << "--> *sound of a HUNGRY dogue* Cherie heads towards bowls' room" << endl;
		pCherie->ChangeLocus(bowls_room);
	}
	return ;
}

void Eating::Run (Cherie* pCherie){
	pCherie->FedLevelpp(1);
	if (RANDOM_NUM>0.7f){pCherie->Staminapp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << "*that sound of a dog eating* Cherie eats like a doge !!" << endl;
	if (pCherie->IsFed()){
		pCherie->ChangeState(Eating::Instance());
	}
	else if (pCherie->IsThirsty()){
		cout << "--> Cherie heads the other bowl" << endl;
		pCherie->ChangeState(Drinking::Instance());
	}
	else if (pCherie->IsTired()){
		pCherie->ChangeState(Lain::Instance());
	}
	else{
		pCherie->ChangeState(Scratching::Instance());
	}
	return ;
}

void Eating::Exit (Cherie* pCherie){
	cout << "--> *Woof woof!* Cherie is done eating like a doge" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Drinking* Drinking::Instance(){
	static Drinking instance;
	return &instance;
}

void Drinking::Enter(Cherie* pCherie){
	if((pCherie->GetLocus()!=bowls_room) && (pCherie->IsThirsty())){
		cout << "--> *puffy dog sound* Cherie needs wateeeeeer" << endl;
		pCherie->ChangeLocus(bowls_room);
	}
	return ;
}

void Drinking::Run (Cherie* pCherie){
	pCherie->ThirstLevelpp(-1);
	pCherie->BladderLevelpp(1);
	if (RANDOM_NUM>0.7f){pCherie->Staminapp(1);}
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << "*that sound of a dog drinking* Cherie is drinking water like a dog" << endl;
	if (!pCherie->IsThirsty()){
		pCherie->ChangeState(Drinking::Instance());
	}
	else if (pCherie->IsFed()){
		cout << "--> Cherie heads the other bowl" << endl;
		pCherie->ChangeState(Eating::Instance());
	}
	return ;
}

void Drinking::Exit(Cherie* pCherie){
	cout << "--> *spills water allover* Cherie is done fericiously drinking water";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Scratching* Scratching::Instance(){
	static Scratching instance;
	return &instance;
}

void Scratching::Enter(Cherie* pCherie){
	if(pCherie->GetLocus()!= annas_room){
		cout << "--> *dog paws shaking* Cherie feels an urge to scratch herself then heads towards Anna's room" << endl;
		pCherie->ChangeLocus(annas_room);
	}
}

void Scratching::Run(Cherie* pCherie){
	pCherie->Staminapp(-1);
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	cout << "*KaPOW!* Cherie ferociously swipes her paws into her own fur" << endl;
	if(pCherie->IsTired()){
		pCherie->ChangeState(Lain::Instance());
	}
	else if (pCherie->IsThirsty()){
		pCherie->ChangeState(Drinking::Instance());
	}
	else if (pCherie->IsBladderFull()){
		pCherie->ChangeState(Pissing::Instance());
	}
	else{
		pCherie->ChangeState(Scratching::Instance());
	}
}

void Scratching::Exit(Cherie* pCherie){
	cout << "--> *satisfaction sigh* Cherie is done pleasing her scratching urges" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Begging* Begging::Instance(){
	static Begging instance;
	return &instance;
}

void Begging::Enter(Cherie* pCherie){
	if(pCherie->GetLocus()!=dining_room){
		cout << "--> *Whining* Cherie can smell the food from far..." << endl;
		pCherie->ChangeLocus(dining_room);
	}
	return ;
}

void Begging::Run(Cherie* pCherie){
	pCherie->Staminapp(-1);
	pCherie->TimeUpdate();
	pCherie->ShowTime();
	if (RANDOM_NUM>0.5f){
		cout << "--> There it is, Cherie *Cherie grabs thrown food midair*" << endl;
		pCherie->ChangeState(Eating::Instance());
	}
	else {
		cout << "--> Bad dog!! No food for you!!" << endl;
		if (pCherie->IsBladderFull()){
			cout << "--> OOoh no, Cherie, not again!!" << endl;
			pCherie->ChangeState(Pissing::Instance());
		}
		else if (!(pCherie->IsFed())){
			pCherie->ChangeState(Eating::Instance());
		}
		else {
			pCherie->ChangeState(Begging::Instance());
		}
	}
	return ;
}

void Begging::Exit(Cherie* pCherie){
	cout << "--> *whining* Looks like Cherie is tired of begging..." << endl ;
	return ;
}