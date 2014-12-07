//============================================================================
// Name        : Philosopher.cpp
// Author      : Albin Engström
// Description : Implementation of class Philosopher
//============================================================================

#include "Philosopher.h"

Philosopher::Philosopher() {

	//Seed rand
	srand(time(NULL));

}

Philosopher::~Philosopher() {
	// TODO Auto-generated destructor stub
}

void Philosopher::Run(){

	//Print that thinking is happening
	std::cout << "Thinking..." << std::endl;

	//Randomize the number of seconds to think
	int seconds = rand() % 5 + 1;

	//Create a duration for thread to sleep
	std::chrono::seconds sleepDuration(seconds);

	//Sleep for said duration
	std::this_thread::sleep_for(sleepDuration);



}
