//============================================================================
// Name        : Table.h
// Author      : Albin Engström
// Description : Declaration of class Table
// Purpose	   : Handle the Chopsticks and the Philosophers
//============================================================================

#ifndef TABLE_H_
#define TABLE_H_

#include"Philosopher.h"

class Table {
public:
	Table(int philosophers, int bowls, std::string logFile);
	virtual ~Table();
};

#endif /* TABLE_H_ */
