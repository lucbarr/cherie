#ifndef STATE_H
#define STATE_H


/*///////////////////////////////////////////////////////////////////
//////////////////////// file : State.h /////////////////////////////
	description:
		Header file for the sake of State class definition.
	Here we state State's polymorphism with its basic functions:
	Enter in a state, run a state and exit a state.
/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////*/

class Cherie ;

class State {
	
	public:
		virtual ~State(){}

		virtual void Enter(Cherie*)=0;
		virtual void Run (Cherie*)=0;
		virtual void Exit (Cherie*)=0;
};


#endif