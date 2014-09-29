#include <iostream>
#include <cstdlib>

#include "../FactoryPattern.h"
#include "../StrategyPattern.h"

/*------------- Test Factory Pattern -------------*/

void FactoryTest()
{	

	SimpleFactory sf;
	CommonFactoryA cfa;
	CommonFactoryB cfb;
	AbstractFactoryA afa;
	AbstractFactoryB afb;

	cout << "���Թ���ģʽ" << endl;
	cout << endl;

	SingleCore *a = sf.createSingleCore(CORE_A);
	SingleCore *b = sf.createSingleCore(CORE_B);
	SingleCore *c = cfa.createSingleCore();
	SingleCore *d = cfb.createSingleCore();
	SingleCore *e = afa.createSingleCore();
	SingleCore *f = afb.createSingleCore();
	MultiCore *g = afa.createMultiCore();
	MultiCore *h = afb.createMultiCore();


	a->show();
	b->show();
	c->show();
	d->show();
	e->show();
	f->show();
	g->Show();
	h->Show();

	cout << endl;

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	delete h;
}


//		Test Strategy Pattern
void StrategyTest()
{

	int a = 9, b = 3;
	ComputerA ca;
	ComputerB cb;
	ComputerC cc;
	ComputerD cd;

	cout << "���Բ���ģʽ" << endl;
	cout << endl;
	cout << "a = " << a << endl << "b = " << b << endl << endl;
	ca.setAlgorithm(new Add());
	cb.setAlgorithm(new Sub());
	cc.setAlgorithm(new Multi());
	cd.setAlgorithm(new Devide());

	ca.calc(a, b);
	cb.calc(a, b);
	cc.calc(a, b);
	cd.calc(a, b);

	cout << endl;
	cout << "��̬�ı��㷨: ���ӷ���Ϊ�˷�" << endl;
	cout << endl;

	ca.setAlgorithm(new Multi());

	ca.calc(a, b);
	cb.calc(a, b);
	cc.calc(a, b);
	cd.calc(a, b);
	cout << endl;

}
