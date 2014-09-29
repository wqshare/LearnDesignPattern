#pragma once

#include <iostream>

using namespace std;

//����ģʽ - Strategy
//���ﶨ��һϵ�м����㷨,�̳��� Calc ����

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

// ���弸�ּ��������
// �ٶ�ÿ�ּ��������һ�ּ��㷽ʽ
// ʹ�ò���ģʽ����ÿ������ά��һ�������㷨��ʵ��,ͨ���ø�ʵ��ָ��ͬ�������㷨��ʵ�ֲ�ͬ�ļ��㷽ʽ.

// Ϊʲô�����ýӿ�/������ķ�ʽ��ֱ����������ʵ����Ϊ����(calc����)�أ�
// ����зǳ����ּ�������ͣ����е�һ��������ͬ���㷨����ô��ÿ�������ж�����ʵ����ͬ���㷨�����˺ܶ��ظ��Ĺ���������ÿ����һ�����ͣ���Ҫȥʵ��һ��
// ���㷨��Ҫ�ı��ʱ��ÿ��ʹ�������㷨�����͵ĺ����������޸ģ�ά�������ǳ����ѡ�
// ��ʹ�ò���ģʽ��ʱ��ֻ��ҪΪÿ������������ָ��һ���㷨���Ϳ��ԴﵽĿ�ģ����ҷ�װ���㷨��ϸ�ڣ�ʹ�����߲��ع��ġ��޸ĵ�ʱ��Ҳֻ���޸ĸ��㷨���ͼ��� 
// ����ģʽ���и��ŵ���ǿ����������ж�̬�ĸı���Ϊ(ͨ������/�ı��㷨��ʵ��)
// ����˵������ģʽ���ǽ�"�仯"���������ʹ�������ʹ���߶������仯.
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

	//���ﻹ���Խ�Ϲ���ģʽ�����ɲ�ͬ���㷨ʵ�����˴�����
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