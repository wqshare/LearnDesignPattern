#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

enum CoreType
{
	CORE_A,
	CORE_B
};


class SingleCore
{
public:
	virtual void show() = 0;
};

class SingleCoreA : public SingleCore
{
public:
	inline void show(){ cout << "SingleCore A" << endl;}
};

class SingleCoreB : public SingleCore
{
public:
	inline void show(){ cout << "SingleCore B" << endl;}
};


/************************************************************************/
/*                                Factory                               */
/************************************************************************/

class SimpleFactory
{
public:
	SingleCore *createSingleCore(enum CoreType t)
	{
		if(t == CORE_A)
		{
			return new SingleCoreA();
		}

		if(t == CORE_A)
		{
			return new SingleCoreB();
		}

		return NULL;
	};
};


class CommonFactoryA : public SimpleFactory
{
public:
	SingleCore *createSingleCore()
	{
		return new SingleCoreA();
	};
};

class CommonFactoryB : public SimpleFactory
{
public:
	SingleCore *createSingleCore()
	{
		return new SingleCoreB();
	};
};

