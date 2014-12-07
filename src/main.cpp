//============================================================================
// Name        : main.cpp
// Author      : Albin Engström
// Description : main of project dining-philosophers
// Purpose	   : Start the program
//============================================================================

#include"Table.h"

#include <thread>

int main() {

	Table table = Table(5, 5);

	table.Run();



	return 0;
}
