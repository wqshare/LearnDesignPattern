#include <iostream>
#include <cstdlib>

#include "FactoryPattern.h"
#include "test/test.h"

int main(int argc, char *argv[])
{
	FactoryTest();

	StrategyTest();
	
	system("pause");

	exit(0);
}