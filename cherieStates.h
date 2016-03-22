#ifndef CHERIE_STATES_H
#define CHERIE_STATES_H
#include "State.h"
#include "cherie.h"


class Cherie ;

class Lain : public State {

	public:
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Pissing : public State {

	public:
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Scratching : public State {

	public:
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Begging : public State {

	public:
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Eating : public State {

	public:
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Drinking : public State {

	public:
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

#endif