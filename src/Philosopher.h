//============================================================================
// Name        : Philosopher.h
// Author      : Albin Engström
// Description : Declaration of class Philosopher
// Purpose	   : Eat and think
//============================================================================

#ifndef PHILOSOPHER_H_
#define PHILOSOPHER_H_

#include<iostream>
#include<cstdlib>
#include<chrono>
#include<thread>

class Philosopher {
public:
	Philosopher();
	virtual ~Philosopher();

	void Run();
	//Pre:
	//Post: The Philosopher proceeds to eat and think
};

#endif /* PHILOSOPHER_H_ */
