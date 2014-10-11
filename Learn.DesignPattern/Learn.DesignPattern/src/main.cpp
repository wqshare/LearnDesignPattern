#include <iostream>
#include <cstdlib>

#include "FactoryPattern.h"
#include "test/test.h"

int main(int argc, char *argv[])
{
	SingleCoreA *s = new SingleCoreA();
	s->foo();

	FactoryTest();

	StrategyTest();
	
	system("pause");

	exit(0);
}