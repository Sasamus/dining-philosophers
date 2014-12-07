//============================================================================
// Name        : Table.cpp
// Author      : Albin Engström
// Description : Implementation of class Table
//============================================================================

#include "Table.h"

Table::Table(int nrPhilosophers, int nrBowls) {

	//Create a Chopstick for every Philosopher
	for(int i = 0; i < nrPhilosophers; i++){
		chopsticks.push_back(new Chopstick());
	}

	//Create Philosophers with their respective Chopsticks
	for(int i = 0; i < nrPhilosophers; i++){

		//The left Chopstick of the first Philosopher have to be the last Chopstick, the table is round
		if(i == 0){
			philosophers.push_back(new Philosopher(chopsticks.back(), chopsticks[i]));
		}

		//The rest of the Philosophers
		philosophers.push_back(new Philosopher(chopsticks[i - 1], chopsticks[i]));
	}


}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

void Table::Run(){

	//Create a thread for every Philosopher in Philosophers Run method
	for(Philosopher *philosopher : philosophers){
		threads.push_back(new std::thread(&Philosopher::Run, philosopher));
	}
}
