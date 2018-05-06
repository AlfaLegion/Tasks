#include "coursework.h"

CourseWork::CourseWork(QWidget *parent)
	: QWidget(parent)
{
	//Сетевая задача

	costs.resize(p);
	produs.resize(p);
	cons.resize(c);

	fl.open("costs.txt");
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int a;
			fl >> a;
			costs[i].push_back(std::pair<int, int>(a, -1));
		}
	}
	fl.close();

	fl.open("prod.txt");
	for (int i = 0; i < p; i++)
		fl >> produs[i];
	fl.close();

	fl.open("cons.txt");
	for (int i = 0; i < c; i++)
		fl >> cons[i];
	fl.close();
	ui.setupUi(this);
	search_basic_plan(costs, produs, cons);
	
	opt_plan(costs, produs, cons,*(ui.tableWidget));
	//

	
	// ЗАгрузка ПЗУ
	HMODULE hLib = LoadLibraryA("MyDLL.dll");
	if (hLib == NULL)
	{
		qDebug("Error not load dll");
	}
	task_packing foo = reinterpret_cast<task_packing>(GetProcAddress(hLib, "task_packing"));
	if (!foo)
	{
		qDebug("error call function");
	}
	y_last = foo(N, h, B, size, eps, y_set, x_set, heft, probob, counters, tables);
	FreeLibrary(hLib);
	QString str;

	for (auto& x : y_set)
	{
		str.push_back(QString::number(x));
		str.push_back("; ");
	}

	ui.label_2->setText(str);
	str.clear();

	for (auto& x : x_set)
	{
		str.push_back(QString::number(x));
		str.push_back("; ");
	}
	ui.label_4->setText(str);
	str.clear();

	double rez = 0;
	for (int i = 0; i<x_set.size(); i++)
	{
		rez += x_set[i] * probob[i];
	}
	str.push_back(QString::number(rez));
	ui.label_6->setText(str);
	ui.label_8->setText(QString::number(y_last));
	
}

CourseWork::~CourseWork()
{

}
