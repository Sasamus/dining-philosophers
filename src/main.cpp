//============================================================================
// Name        : main.cpp
// Author      : Albin Engström
// Description : main of project dining-philosophers
// Purpose	   : Start the program
//============================================================================

#include"Philosopher.h"

#include <thread>

int main() {

	std::thread *thread = new std::thread(&Philosopher::Run, Philosopher());

	thread->join();

	delete thread;

	return 0;
}
