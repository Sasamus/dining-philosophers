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
