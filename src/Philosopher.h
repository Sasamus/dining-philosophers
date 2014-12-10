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
#include<mutex>
#include<fstream>

class Philosopher {
public:
	Philosopher(std::mutex *chopstickLeft, std::mutex *chopstickRight,
			int nrBowls, int placement, std::string logFileName);
	virtual ~Philosopher();

	void Run();
	//Pre:
	//Post: The Philosopher proceeds to eat and think

	void Sleep();
	//Pre:
	//Post: The tread sleeps for 1-5 seconds

private:
	//Pointers to mutexes for the left and right chopstick
	std::mutex *mChopstickLeft;
	std::mutex *mChopstickRight;

	//A static mutex to sync cout usage across instances of the class
	static std::mutex *mCoutMutex;

	//A static int to keep track of how many class instances are eating
	static int mNrEating;

	//Ints for the nr of bowls to eat and placement at the table
	int mNrBowls;
	int mPlacement;

	//Holds the log file's name
	std::string mLogFileName;
};

#endif /* PHILOSOPHER_H_ */
