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

class MultiCore      
{    
public:    
	virtual void Show() = 0;  
};    
class MultiCoreA : public MultiCore      
{    
public:    
	void Show() { cout<<"Multi Core A"<<endl; }    

};    
class MultiCoreB : public MultiCore      
{    
public:    
	void Show() { cout<<"Multi Core B"<<endl; }    
};

/************************************************************************/
/*                                Factory                               */
/************************************************************************/

class SimpleFactory
{
public:
	SingleCore *createSingleCore(enum CoreType t)
	{		
		switch (t)
		{
		case CORE_A:
			return new SingleCoreA();
		case CORE_B:
			return new SingleCoreB();
		default:
			return NULL;
		}
	};
};


class CommonFactoryA 
{
public:
	SingleCore *createSingleCore()
	{
		return new SingleCoreA();
	};
};

class CommonFactoryB
{
public:
	SingleCore *createSingleCore()
	{
		return new SingleCoreB();
	};
};


class AbstractFactory
{
public:
	virtual SingleCore *createSingleCore() = 0;
	virtual MultiCore *createMultiCore() = 0;
};

class AbstractFactoryA : AbstractFactory
{
public:
	SingleCore *createSingleCore() override
	{
		return new SingleCoreA();
	}

	MultiCore *createMultiCore() override
	{
		return new MultiCoreA();
	}
};

class AbstractFactoryB : AbstractFactory
{
public:
	SingleCore *createSingleCore() override
	{
		return new SingleCoreB();
	}

	MultiCore *createMultiCore() override
	{
		return new MultiCoreB();
	}
};