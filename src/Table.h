//============================================================================
// Name        : Table.h
// Author      : Albin Engström
// Description : Declaration of class Table
// Purpose	   : Handle the Chopsticks and the Philosophers
//============================================================================

#ifndef TABLE_H_
#define TABLE_H_

#include"Philosopher.h"

#include<vector>
#include<thread>
#include<mutex>
#include<fstream>

class Table {
public:
	Table(int nrPhilosophers, int nrBowls, std::string logFileName);
	virtual ~Table();

	void Run();
	//Pre:
	//Post: Starts the meal

private:
	std::vector<Philosopher*> mPhilosophers;
	std::vector<std::mutex*> mChopsticks;
	std::ofstream *mLogFile;
	std::mutex *mOutputMutex;
};

#endif /* TABLE_H_ */
