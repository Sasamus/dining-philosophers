//============================================================================
// Name        : Philosopher.cpp
// Author      : Albin Engström
// Description : Implementation of class Philosopher
//============================================================================

#include "Philosopher.h"

Philosopher::Philosopher(Chopstick *chopstickLeft, Chopstick *chopstickRight)
: mChopstickLeft(chopstickLeft), mChopstickRight(chopstickRight){

	//Seed rand
	srand(time(NULL));

}

Philosopher::~Philosopher() {
	// TODO Auto-generated destructor stub
}

void Philosopher::Run(){

	for(unsigned int i=0; i < 10; i++){

		//Print that thinking is happening
		std::cout << "Thinking..." << std::endl;

		//Sleep
		Sleep();

		//Print that eating is happening
		std::cout << "Eating..." << std::endl;

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
