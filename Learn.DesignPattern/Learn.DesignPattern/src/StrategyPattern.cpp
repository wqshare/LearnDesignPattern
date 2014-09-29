#include "StrategyPattern.h"


BaseComputer::BaseComputer():_calc(NULL)
{

}

BaseComputer::~BaseComputer()
{
	if(_calc)
	{
		delete _calc;
		_calc = NULL;
	}
}
