#ifndef CHERIE_STATES_H
#define CHERIE_STATES_H
#include "State.h"
#include "cherie.h"


class Cherie ;

class Lain : public State {

	public:
		static Lain* Instance();
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Pissing : public State {

	public:
		static Pissing* Instance();
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Scratching : public State {

	public:
		static Scratching* Instance();
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Begging : public State {

	public:
		static Begging* Instance();
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Eating : public State {

	public:
		static Eating* Instance();
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

class Drinking : public State {

	public:
		static Drinking* Instance();
		virtual void Enter (Cherie* cherie);
		virtual void Run (Cherie* cherie);
		virtual void Exit (Cherie* cherie);	
};

#endif