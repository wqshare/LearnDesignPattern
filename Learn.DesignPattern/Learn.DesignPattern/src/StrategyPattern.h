#pragma once

#include <iostream>

using namespace std;

//策略模式 - Strategy
//这里定义一系列计算算法,继承于 Calc 类型

class Calc
{
public:
	virtual void doCalc(int a, int b) = 0; 
};

class Add : public Calc
{
public:
	void doCalc(int a, int b) override
	{
		cout << "a + b = " << a + b << endl;
	}
};

class Sub : public Calc
{
public:
	void doCalc(int a, int b) override
	{
		cout << "a - b = " << a - b << endl;
	}
};

class Multi : public Calc
{
public:
	void doCalc(int a, int b) override
	{
		cout << "a x b = " << a * b << endl;
	}
};

class Devide : public Calc
{
public:
	void doCalc(int a, int b) override
	{
		cout << "a / b = " << a / b << endl;
	}
};

// 定义几种计算机类型
// 假定每种计算机都有一种计算方式
// 使用策略模式，在每个类中维护一个基类算法的实例,通过让该实例指向不同的子类算法，实现不同的计算方式.

// 为什么不采用接口/抽象类的方式，直接在子类里实现行为函数(calc函数)呢？
// 如果有非常多种计算机类型，其中的一部分有相同的算法，那么在每种类型中都必须实现相同的算法，多了很多重复的工作，而且每新增一种类型，都要去实现一次
// 当算法需要改变的时候，每个使用这种算法的类型的函数都必须修改，维护起来非常困难。
// 当使用策略模式的时候，只需要为每个新增的类型指定一种算法，就可以达到目的，并且封装了算法的细节，使调用者不必关心。修改的时候也只需修改该算法类型即可 
// 策略模式还有个优点就是可以在运行中动态的改变行为(通过设置/改变算法的实例)
// 所以说，策略模式就是将"变化"剥离出来，使其独立于使用者而独立变化.
class BaseComputer
{
public:
	BaseComputer();
	virtual ~BaseComputer();

	virtual void calc(int a, int b)
	{
		if(_calc)
			_calc->doCalc(a, b);
	}

	//这里还可以结合工厂模式，生成不同的算法实例，此处不表
	void setAlgorithm(Calc *c)
	{
		if(_calc)
			delete _calc;
		_calc = c;
	}

private:
	Calc * _calc;
};

class ComputerA : public BaseComputer
{

};

class ComputerB : public BaseComputer
{

};

class ComputerC : public BaseComputer
{

};

class ComputerD : public BaseComputer
{

};