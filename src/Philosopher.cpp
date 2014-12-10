//============================================================================
// Name        : Philosopher.cpp
// Author      : Albin Engström
// Description : Implementation of class Philosopher
//============================================================================

#include "Philosopher.h"

//Create a mutex
std::mutex *Philosopher::mOutputMutex = new std::mutex();

int Philosopher::mNrEating = 0;

Philosopher::Philosopher(std::mutex *chopstickLeft, std::mutex *chopstickRight,
		int nrBowls, int placement, std::string logFileName)
:mChopstickLeft(chopstickLeft), mChopstickRight(chopstickRight),
 mNrBowls(nrBowls), mPlacement(placement), mLogFileName(logFileName) {

	//Seed rand
	srand(time(NULL));

}

Philosopher::~Philosopher(){

}

void Philosopher::Run() {

	//Create and open the log file
	std::ofstream logFile;
	logFile.open (mLogFileName);

	//Strings to hold the output
	std::string outputString1;
	std::string outputString2;

	//Print and log that thinking is happening
	mOutputMutex->lock();

	outputString1 = "Philosopher " + std::to_string(mPlacement) + " is thinking.";
	outputString2 = "Philosophers currently eating: " + std::to_string(mNrEating);

	std::cout << outputString1 << std::endl;
	logFile << outputString1 << std::endl;

	std::cout << outputString2 << std::endl;
	logFile << outputString2 << std::endl;

	std::cout << std::endl;
	logFile << std::endl;

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
		logFile << outputString1 << std::endl;

		std::cout << outputString2 << std::endl;
		logFile << outputString2 << std::endl;

		std::cout << std::endl;
		logFile << std::endl;

		mOutputMutex->unlock();

		//Create lock guards with the mutexes in their already locked state
		std::lock_guard<std::mutex> lockLeft(*mChopstickLeft, std::adopt_lock);
		std::lock_guard<std::mutex> lockRight(*mChopstickRight, std::adopt_lock);

		//Print that eating is happening
		mOutputMutex->lock();

		outputString1 = "Philosopher " + std::to_string(mPlacement) + " is eating.";
		outputString2 = "Philosophers currently eating: " + std::to_string(++mNrEating);

		std::cout << outputString1 << std::endl;
		logFile << outputString1 << std::endl;

		std::cout << outputString2 << std::endl;
		logFile << outputString2 << std::endl;

		std::cout << std::endl;
		logFile << std::endl;

		mOutputMutex->unlock();

		//Sleep
		Sleep();

		//Print that thinking is happening
		mOutputMutex->lock();

		outputString1 = "Philosopher " + std::to_string(mPlacement) + " is thinking.";
		outputString2 = "Philosophers currently eating: " + std::to_string(--mNrEating);

		std::cout << outputString1 << std::endl;
		logFile << outputString1 << std::endl;

		std::cout << outputString2 << std::endl;
		logFile << outputString2 << std::endl;

		std::cout << std::endl;
		logFile << std::endl;

		mOutputMutex->unlock();

		//Sleep
		Sleep();
	}

	//Close logFile
	logFile.close();
}

void Philosopher::Sleep() {

	//Randomize the number of seconds to sleep
	int seconds = rand() % 5 + 1;

	//Create a duration for thread to sleep
	std::chrono::seconds duration(seconds);

	//Sleep for said duration
	std::this_thread::sleep_for(duration);
}
