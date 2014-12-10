//============================================================================
// Name        : main.cpp
// Author      : Albin Engström
// Description : main of project dining-philosophers
// Purpose	   : Start the program
//============================================================================

#include"Table.h"
#include"Philosopher.h"

#include <thread>

/*
 * I'll first note that I've worked with an alternative version of the "Dining Philosophers" problem
 * where instead of spaghetti and forks, rice and chopsticks are used. It just seems to make more sense
 * in an admittedly strange situation where clean eating utensils are rare.
 *
 * My solution works with a Table class that holds information about the
 * philosophers seated around it and the chopsticks placed on it.
 *
 * The Philosophers are made aware of the the chopsticks, which are implemented as mutexes, on either side of them.
 * While the philosophers go through their cycle of eating and thinking they use the lock function
 * from the <mutex> library to lock two mutexes (the chopsticks) at once or wait until both are available,
 * this eliminates the risk of deadlock.
 *
 * And using the "eating = philosophers/2" algorithm to asses how it performs
 * it seems to achieve this number consistently.
 */
int main(int argc, char* argv[]) {

	//A table pointer
	Table *table;

	//Crate a Table object depending on arguments
	if(argc == 1){
		table = new Table(6, 5, "philo.log");
	}
	else if(argc == 2){
		table = new Table(atoi(argv[1]), 5, "philo.log");
	}
	else if(argc == 3){
		table = new Table(atoi(argv[1]), atoi(argv[2]), "philo.log");
	}
	else if(argc == 4){
		table =  new Table(atoi(argv[1]), atoi(argv[2]), argv[3]);
	}

	//Run table
	table->Run();

	//Delete table
	delete table;

	//Return 0
	return 0;
}
