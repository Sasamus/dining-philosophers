//============================================================================
// Name        : Philosopher.cpp
// Author      : Albin Engström
// Description : Implementation of class Philosopher
//============================================================================

#include "Philosopher.h"

Philosopher::Philosopher(Chopstick *chopstickLeft, Chopstick *chopstickRight, int nrBowls)
: mChopstickLeft(chopstickLeft), mChopstickRight(chopstickRight), mNrBowls(nrBowls){

	//Seed rand
	srand(time(NULL));

}

Philosopher::~Philosopher() {
	// TODO Auto-generated destructor stub
}

void Philosopher::Run(){

	for(int i=0; i < mNrBowls; i++){

		//Print that thinking is happening
		mCoutMutex.lock();
		std::cout << "Thinking...\n";
		mCoutMutex.unlock();

		//Sleep
		Sleep();

		//Print that eating is happening
		mCoutMutex.lock();
		std::cout << "Eating...\n";
		mCoutMutex.unlock();

		//Sleep
		Sleep();
	}
}

void Philosopher::Sleep(){

	//Randomize the number of seconds to sleep
	int seconds = rand() % 5 + 1;

	//Create a duration for thread to sleep
	std::chrono::seconds duration(seconds);

	//Sleep for said duration
	std::this_thread::sleep_for(duration);
}
