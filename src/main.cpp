//============================================================================
// Name        : main.cpp
// Author      : Albin Engström
// Description : main of project dining-philosophers
// Purpose	   : Start the program
//============================================================================

#include"Table.h"
#include"Philosopher.h"

#include <thread>

int main(int argc, char* argv[]) {

	//A table pointer
	Table *table;

	//Crate a Table object depending on arguments
	if(argc == 0){
		table = new Table(6, 5, "philo.log");
	}
	else if(argc == 1){
		table = new Table(atoi(argv[0]), 5, "philo.log");
	}
	else if(argc == 2){
		table = new Table(atoi(argv[0]), atoi(argv[1]), "philo.log");
	}
	else if(argc == 2){
		table =  new Table(atoi(argv[0]), atoi(argv[1]), argv[2]);
	}

	//Run table
	table->Run();

	//Delete table
	delete table;

	//Return 0
	return 0;
}
