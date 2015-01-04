//============================================================================
// Name        : Table.cpp
// Author      : Albin Engström
// Description : Implementation of class Table
//============================================================================

#include "Table.h"

Table::Table(int nrPhilosophers, int nrBowls, std::string logFileName) {

	//Create and open the log file
	mLogFile = new std::ofstream();
	mLogFile->open (logFileName);

	//Create a Chopstick for every Philosopher
	for(int i = 0; i < nrPhilosophers; i++){
		mChopsticks.push_back(new std::mutex());
	}

	//Create Philosophers with their respective Chopsticks
	for(int i = 0; i < nrPhilosophers; i++){

		//The left Chopstick of the first Philosopher have to be the last Chopstick, the table is round
		if(i == 0){
			mPhilosophers.push_back(new Philosopher(mChopsticks.back(), mChopsticks[i], nrBowls, i, mLogFile));
		}else{
			//The rest of the Philosophers
			mPhilosophers.push_back(new Philosopher(mChopsticks[i - 1], mChopsticks[i], nrBowls, i, mLogFile));
		}
	}
}

Table::~Table() {

	//Delete all Philosophers in mPhilosophers
	for(Philosopher *philosopher : mPhilosophers){
		delete philosopher;
	}

	//Delete all mutexes is mChopsticks
	for(std::mutex *chopstick : mChopsticks){
		delete chopstick;
	}

	//Close mLogFile
	mLogFile->close();
}

void Table::Run(){

	//Holds the threads
	std::vector<std::thread> threads;

	//Create a thread for every Philosopher in Philosophers Run method
	for(Philosopher *philosopher : mPhilosophers){
		threads.push_back(std::thread(&Philosopher::Run, philosopher));
	}

	//Join all threads
	for(unsigned int i=0; i < threads.size(); i++){
		threads.at(i).join();
	}
}
