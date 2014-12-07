//============================================================================
// Name        : Philosopher.h
// Author      : Albin Engström
// Description : Declaration of class Philosopher
// Purpose	   : Eat and think
//============================================================================

#ifndef PHILOSOPHER_H_
#define PHILOSOPHER_H_

#include"Chopstick.h"

#include<iostream>
#include<cstdlib>
#include<chrono>
#include<thread>
#include<mutex>

class Philosopher {
public:
	Philosopher(Chopstick *chopstickLeft, Chopstick *chopstickRight);
	virtual ~Philosopher();

	void Run();
	//Pre:
	//Post: The Philosopher proceeds to eat and think

	void Sleep();
	//Pre:
	//Post: The tread sleeps for 1-5 seconds

private:
	Chopstick *mChopstickLeft;
	Chopstick *mChopstickRight;
	std::mutex mCoutMutex;
};

#endif /* PHILOSOPHER_H_ */
