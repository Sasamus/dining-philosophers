//============================================================================
// Name        : Philosopher.cpp
// Author      : Albin Engström
// Description : Implementation of class Philosopher
//============================================================================

#include "Philosopher.h"

//Create a mutex
std::mutex *Philosopher::mCoutMutex = new std::mutex();

int Philosopher::mNrEating = 0;

Philosopher::Philosopher(std::mutex *chopstickLeft, std::mutex *chopstickRight, int nrBowls, int placement)
:mChopstickLeft(chopstickLeft), mChopstickRight(chopstickRight), mNrBowls(nrBowls), mPlacement(placement) {

	//Seed rand
	srand(time(NULL));

}

Philosopher::~Philosopher(){

}

void Philosopher::Run() {

	//Print that thinking is happening
	mCoutMutex->lock();
	std::cout << "Philosopher " << mPlacement << " is thinking." << std::endl;
	std::cout << "Philosophers currently eating: " << mNrEating << std::endl;
	std::cout << std::endl;
	mCoutMutex->unlock();

	//Sleep
	Sleep();

	for (int i = 0; i < mNrBowls; i++) {

		//Locks the chopsticks
		lock(*mChopstickLeft, *mChopstickRight);

		//Print that chopsticks have been acquired
		mCoutMutex->lock();
		std::cout << "Philosopher " << mPlacement << " have acquired both chopsticks." << std::endl;
		std::cout << "Philosophers currently eating: " << mNrEating << std::endl;
		std::cout << std::endl;
		mCoutMutex->unlock();

		//Create lock guards with the mutexes in their already locked state
		std::lock_guard<std::mutex> lockLeft(*mChopstickLeft, std::adopt_lock);
		std::lock_guard<std::mutex> lockRight(*mChopstickRight, std::adopt_lock);

		//Print that eating is happening
		mCoutMutex->lock();
		std::cout << "Philosopher " << mPlacement << " is eating." << std::endl;
		std::cout << "Philosophers currently eating: " << ++mNrEating << std::endl;
		std::cout << std::endl;
		mCoutMutex->unlock();

		//Sleep
		Sleep();

		//Print that thinking is happening
		mCoutMutex->lock();
		std::cout << "Philosopher " << mPlacement << " is thinking." << std::endl;
		std::cout << "Philosophers currently eating: " << --mNrEating << std::endl;
		std::cout << std::endl;
		mCoutMutex->unlock();

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
