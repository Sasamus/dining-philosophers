//============================================================================
// Name        : Philosopher.cpp
// Author      : Albin Engstr��m
// Description : Implementation of class Philosopher
//============================================================================

#include "Philosopher.h"

//Create a mutex
std::mutex *Philosopher::mOutputMutex = new std::mutex();

int Philosopher::mNrEating = 0;

Philosopher::Philosopher(std::mutex *chopstickLeft, std::mutex *chopstickRight,
		int nrBowls, int placement, std::ofstream *logFile)
:mChopstickLeft(chopstickLeft), mChopstickRight(chopstickRight),
 mNrBowls(nrBowls), mPlacement(placement), mLogFile(logFile) {

	//Seed rand
	srand(time(NULL));

}

Philosopher::~Philosopher(){
	//Delete object at mOutputMutex if not already done
	if(mOutputMutex){
		delete mOutputMutex;
	}
}

void Philosopher::Run() {

	//Strings to hold the output
	std::string outputString1;
	std::string outputString2;

	//Print and log that thinking is happening
	mOutputMutex->lock();

	outputString1 = "Philosopher " + std::to_string(mPlacement) + " is thinking.";
	outputString2 = "Philosophers currently eating: " + std::to_string(mNrEating);

	std::cout << outputString1 << std::endl;
	*mLogFile << outputString1 << std::endl;

	std::cout << outputString2 << std::endl;
	*mLogFile << outputString2 << std::endl;

	std::cout << std::endl;
	*mLogFile << std::endl;

	mOutputMutex->unlock();

	//Sleep
	Sleep();

	for (int i = 0; i < mNrBowls; i++) {

		//Locks the chopsticks
		lock(*mChopstickLeft, *mChopstickRight);

		//Print that chopsticks have been acquired
		mOutputMutex->lock();

		outputString1 = "Philosopher " + std::to_string(mPlacement) + " have acquired both chopsticks.";
		outputString2 = "Philosophers currently eating: " + std::to_string(mNrEating);

		std::cout << outputString1 << std::endl;
		*mLogFile << outputString1 << std::endl;

		std::cout << outputString2 << std::endl;
		*mLogFile << outputString2 << std::endl;

		std::cout << std::endl;
		*mLogFile << std::endl;

		mOutputMutex->unlock();

		//Print that eating is happening
		mOutputMutex->lock();

		outputString1 = "Philosopher " + std::to_string(mPlacement) + " is eating.";
		outputString2 = "Philosophers currently eating: " + std::to_string(++mNrEating);

		std::cout << outputString1 << std::endl;
		*mLogFile << outputString1 << std::endl;

		std::cout << outputString2 << std::endl;
		*mLogFile << outputString2 << std::endl;

		std::cout << std::endl;
		*mLogFile << std::endl;

		mOutputMutex->unlock();

		//Sleep
		Sleep();

		//Unlocks chopsticks
		mChopstickLeft->unlock();
		mChopstickRight->unlock();

		//Print that thinking is happening
		mOutputMutex->lock();

		outputString1 = "Philosopher " + std::to_string(mPlacement) + " is thinking.";
		outputString2 = "Philosophers currently eating: " + std::to_string(--mNrEating);

		std::cout << outputString1 << std::endl;
		*mLogFile << outputString1 << std::endl;

		std::cout << outputString2 << std::endl;
		*mLogFile << outputString2 << std::endl;

		std::cout << std::endl;
		*mLogFile << std::endl;

		mOutputMutex->unlock();

		//Sleep
		Sleep();
	}
}

void Philosopher::Sleep() {

	//Randomize the number of seconds to sleep
	int seconds = rand() % 5 + 1;

	//Create a duration for thread to sleep
	std::chrono::seconds duration(seconds);

	//Sleep for said duration
	std::this_thread::sleep_for(duration);
}
