#ifndef STATE_H
#define STATE_H

// Abstract State class

class Cherie ;

class State {
	
	public:
		virtual ~State(){}

		virtual void Enter(Cherie*)=0;
		virtual void Run (Cherie*)=0;
		virtual void Exit (Cherie*)=0;
};


#endif