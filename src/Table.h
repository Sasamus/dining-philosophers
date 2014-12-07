//============================================================================
// Name        : Table.h
// Author      : Albin Engström
// Description : Declaration of class Table
// Purpose	   : Handle the Chopsticks and the Philosophers
//============================================================================

#ifndef TABLE_H_
#define TABLE_H_

#include"Philosopher.h"
#include"Chopstick.h"

#include<vector>
#include<thread>

class Table {
public:
	Table(int nrPhilosophers, int nrBowls);
	virtual ~Table();

	void Run();
	//Pre:
	//Post: Starts the meal

private:
	std::vector<Philosopher*> philosophers;
	std::vector<Chopstick*> chopsticks;
	std::vector<std::thread*> threads;
};

#endif /* TABLE_H_ */
