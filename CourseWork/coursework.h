#ifndef COURSEWORK_H
#define COURSEWORK_H

#include <QtWidgets/QWidget>
#include "ui_coursework.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<fstream>
#include<utility>
#include<iomanip>
#include<sstream>
#include<Windows.h>
#include<stack>
#include<fstream>
using std::vector;
using std::pair;
using std::stack;
using std::fstream;
// Динамическое программирвоание
using tableType = vector<pair<double, double>>;
using vector_table = vector<tableType>;
__forceinline double Func(double x, double p)
{
	return x*p;
}
typedef double(*task_packing)(int, double, double, int, double, vector<double>&, vector<double>&, vector<double>&, vector<double>&, vector<int>&, vector_table&);
// Метод буферного запаса
using Costs = vector<vector<pair<int, int>>>;
using Matrix = vector<vector<int>>;
using PCType = vector<int>;
using counter_type = Costs::size_type;
using char_map = vector<vector<char>>;

template<typename T>
class Adapter
{
private:
	T& object;
private:
	template<typename U>
	class Proxy
	{
	private:
		U& subobjeсе;
	public:
		Proxy() = delete;
		Proxy(U& other) :subobjeсе(other) {}
		Proxy(U&& other) :subobjeсе(other) {};
		decltype(auto) operator[](size_t index)
		{
			return (subobjeсе[index].second);
		}
	};
public:
	Adapter() = delete;
	Adapter(T& _other) :object(_other) {}
	decltype(auto) operator[](size_t index)
	{
		return Proxy<T::value_type>(object[index]);
	}
};

struct cell
{
	int row;
	int col;
	cell() = default;
	cell(int r, int c) :row(r), col(c) {}
};

struct e_cell
{
	int row;
	int col;
	char d;
	e_cell() = default;
	e_cell(int r, int c, char ds) :row(r), col(c), d(ds) {}
};

inline void way_back(stack<e_cell>& st, e_cell& t, Matrix& counters, int s_r, int s_c)
{
	bool flag = true;
	char dis = t.d;
	e_cell next = t;
	e_cell last;
	while (true)
	{
		while (dis == next.d)
		{
			if (st.empty())
				break;
			last = st.top();
			st.pop();
			counters[next.row][next.col] -= 1;
			next = st.top();


		}
		if (last.d != next.d)
		{
			e_cell buff;
			if (last.d == 'U')
			{
				buff = last;
				buff.row -= 1;
			}
			else if (last.d == 'D')
			{
				buff = last;
				buff.row += 1;
			}
			else if (last.d == 'L')
			{
				buff = last;
				buff.col -= 1;
			}
			else if (last.d == 'R')
			{
				buff = last;
				buff.col += 1;
			}
			if ((buff.row == next.row) && (buff.col == next.col))
			{

				counters[buff.row][buff.col] -= 1;
				dis = next.d;
				last = next;
				st.pop();
				next = st.top();
			}
			else
			{
				counters[buff.row][buff.col] -= 1;
				break;

			}

		}
	}

}

template<typename T>
void found_cycle(T& m, Matrix& counters, char_map& map, vector<e_cell>& nodes, int s_r, int s_c, e_cell& st)
{
	stack<e_cell> way;
	way.push(st);
	if (st.row + 1 < s_r)
	{
		way.emplace(st.row + 1, st.col, 'U');
		counters[st.row][st.col] += 1;
	}
	if (0 <= st.row - 1)
	{
		way.emplace(st.row - 1, st.col, 'D');
		counters[st.row][st.col] += 1;
	}
	if (st.col + 1 < s_c)
	{
		way.emplace(st.row, st.col + 1, 'L');
		counters[st.row][st.col] += 1;
	}
	if (0 <= st.col - 1)
	{
		way.emplace(st.row, st.col - 1, 'R');
		counters[st.row][st.col] += 1;
	}
	e_cell current;
	while (true)
	{
		if (way.empty())
		{
			//cerr << "empty stack" << endl;
			break;
		}
		current = way.top();
		if (current.row == st.row&&current.col == st.col)
		{
			//cout << "found cycle" << endl;
			break;
		}
		if (m[current.row][current.col] == -1)
		{
			if (current.d == 'L')
			{

				if (current.col + 1 >= s_c)
				{
					counters[current.row][current.col] += 1;
					way_back(way, current, counters, s_r, s_c); continue;
				}
				way.emplace(current.row, current.col + 1, 'L');
				counters[current.row][current.col] += 1;
				continue;
			}
			if (current.d == 'R')
			{

				if (current.col - 1 < 0)
				{
					counters[current.row][current.col] += 1;
					way_back(way, current, counters, s_r, s_c); continue;
				}
				way.emplace(current.row, current.col - 1, 'R');
				counters[current.row][current.col] += 1;
				continue;
			}
			if (current.d == 'U')
			{

				if (current.row + 1 >= s_r)
				{
					counters[current.row][current.col] += 1;
					way_back(way, current, counters, s_r, s_c); continue;
				}
				way.emplace(current.row + 1, current.col, 'U');
				counters[current.row][current.col] += 1;
				continue;
			}
			if (current.d == 'D')
			{
				if (current.row - 1 < 0)
				{
					counters[current.row][current.col] += 1;
					way_back(way, current, counters, s_r, s_c); continue;
				}
				way.emplace(current.row - 1, current.col, 'D');
				counters[current.row][current.col] += 1;
				continue;
			}
		}
		if (m[current.row][current.col] != -1)
		{
			if (current.row + 1 < s_r)
			{
				if (current.d != 'D')
				{
					way.emplace(current.row + 1, current.col, 'U');
					counters[current.row][current.col] += 1;
				}
			}
			if (0 <= current.row - 1)
			{
				if (current.d != 'U')
				{
					way.emplace(current.row - 1, current.col, 'D');
					counters[current.row][current.col] += 1;
				}
			}
			if (current.col + 1 < s_c)
			{
				if (current.d != 'R')
				{
					way.emplace(current.row, current.col + 1, 'L');
					counters[current.row][current.col] += 1;
				}
			}
			if (current.col - 1 >= 0)
			{
				if (current.d != 'L')
				{
					way.emplace(current.row, current.col - 1, 'R');
					counters[current.row][current.col] += 1;
				}
			}
		}

	}

	vector<e_cell>buffer;
	//vector<e_cell>nodes;
	e_cell temp = way.top();
	way.pop();
	nodes.push_back(temp);
	while (!way.empty())
	{
		buffer.push_back(way.top());
		way.pop();
	}
	char dis = temp.d;

	while (true)
	{
		if (temp.d == 'D')
		{
			temp.row += 1;
		}
		if (temp.d == 'U')
		{
			temp.row -= 1;
		}
		if (temp.d == 'R')
		{
			temp.col += 1;
		}
		if (temp.d == 'L')
		{
			temp.col -= 1;
		}
		//char temp;
		auto it = find_if(buffer.begin(), buffer.end(), [&temp](const e_cell&oth) {return (temp.row == oth.row) && (temp.col == oth.col) && (temp.d == oth.d); });
		if (it == buffer.end())
		{
			it = find_if(buffer.begin(), buffer.end(), [&temp](const e_cell&oth) {return (temp.row == oth.row) && (temp.col == oth.col); });
			if (it == buffer.end())
			{
				//cerr << "bad1" << endl;
				system("pause");
			}
		}
		e_cell buff = *it;
		if (buff.row == st.row&&buff.col == st.col)
			break;
		if (dis != buff.d)
		{
			dis = buff.d;
			nodes.push_back(buff);
			buffer.erase(it);
			temp = nodes.back();
		}

	}

}

inline void upgrade_plan(Costs& _costs, vector<e_cell>& _nodes, e_cell& _start)
{

	bool flag = true;
	for (auto& x : _nodes)
	{
		if (flag)
		{
			x.d = '+';
			flag = false;
			continue;
		}
		x.d = '-';
		flag = true;
	}
	/*for (auto& x : _nodes)
	{
	cout << x.row << " " << x.col << " " << x.d << endl;
	}*/
	// поиск наименьшего значения с '-'
	e_cell min_elem;
	int value_min = INT_MAX;
	for (auto& x : _nodes)
	{
		if (x.d == '-')
		{
			if (_costs[x.row][x.col].second < value_min)
			{
				value_min = _costs[x.row][x.col].second;
				min_elem.row = x.row;
				min_elem.col = x.col;
				min_elem.d = x.d;
			}
		}
	}

	// улучшение плана
	//int counter_zero = 0;
	bool zero = true;
	_costs[_start.row][_start.col].second += 1;
	for (auto& x : _nodes)
	{
		if (x.d == '+')
		{
			_costs[x.row][x.col].second += value_min;
		}
		else
		{
			_costs[x.row][x.col].second -= value_min;
			if (_costs[x.row][x.col].second == 0)
			{
				if (zero)
				{
					_costs[x.row][x.col].second = -1;
					zero = false;
				}

			}
		}
	}
}

inline void search_basic_plan(Costs& _costs, PCType& _producers, PCType& _consumers)
{
	auto count_prod = _costs.size();
	auto count_cons = _costs[0].size();
	auto index = 0;
	for (counter_type i = 0; i < count_prod; i++)
	{
		for (counter_type j = index; j < count_cons; j++)
		{
			if (_consumers[j] >= _producers[i])
			{
				_costs[i][j].second = _producers[i];
				_consumers[j] = _consumers[j] - _producers[i];
				_producers[i] = 0;
			}
			else
			{
				_costs[i][j].second = _consumers[j];
				_producers[i] = _producers[i] - _consumers[j];
				_consumers[j] = 0;
			}
			if (_producers[i] == 0)
			{
				index = j;
				break;
			}
		}
	}

}

inline void opt_plan(Costs& _costs, PCType& _producers, PCType& _consumers,QTableWidget& tb)
{
	tb.setColumnCount(_consumers.size());
	QStringList ls;
	ls << "B1" << "B2" << "B3" << "B1" << "B2" << "M3" << "M4" << "M5";
	tb.setHorizontalHeaderLabels(ls);
	int qwe = 0;
	while (true)
	{
		qwe++;
		PCType poten_V(_consumers.size(), INT_MAX);
		PCType poten_U(_producers.size(), INT_MAX);
		Matrix values(_consumers.size());
		counter_type index_row = 0;
		counter_type index_colum = 0;
		int min_prev_value = 0;
		poten_U[0] = 0;
		bool is_all = true;
		while (true)
		{

			for (counter_type i = 0; i < poten_U.size(); i++)
			{
				for (counter_type j = 0; j < poten_V.size(); j++)
				{
					if (_costs[i][j].second == -1)
						continue;
					if ((poten_V[j] == INT_MAX) && (poten_U[i] == INT_MAX))
					{
						is_all = false;
						continue;
					}
					if (poten_V[j] == INT_MAX)
					{
						poten_V[j] = poten_U[i] + _costs[i][j].first;
						continue;
					}
					if (poten_U[i] == INT_MAX)
					{
						poten_U[i] = poten_V[j] - _costs[i][j].first;
						continue;
					}
				}
			}

			if (is_all)
			{
				break;
			}
			is_all = true;

		}


		//поиск минимального элемента
		for (counter_type i = 0; i < _producers.size(); i++)
		{
			for (counter_type j = 0; j < _consumers.size(); j++)
			{
				int delt = poten_U[i] + _costs[i][j].first - poten_V[j];
				if (delt < min_prev_value)
				{
					min_prev_value = delt;
					index_row = i;
					index_colum = j;
				}
				values[i].push_back(delt);
			}
		}

		//cout << index_row << " " << index_colum << " " << min_prev_value << endl;
		//выход из главного цикла
		if (min_prev_value >= 0)
		{
			break;
		}
		// подготовка и преобразвоание вспомогательных данных
		Adapter<Costs> def(_costs);
		vector<e_cell> nodes;
		char_map map;
		Matrix counters;
		e_cell start(index_row, index_colum, 'S');
		int s_r = _costs.size();
		int s_c = _costs[0].size();
		for (int i = 0; i < s_r; i++)
		{
			map.emplace_back(vector<char>());
			counters.emplace_back(vector<int>());
			for (int j = 0; j < s_c; j++)
			{
				map[i].push_back(0);
				counters[i].push_back(0);
			}
		}

		// тут поиск цикла
		found_cycle(def, counters, map, nodes, s_r, s_c, start);

		/*for (int i = 0; i < s_r; i++)
		{
		for (int j = 0; j < s_c; j++)
		{
		cout << counters[i][j]<<" ";
		}
		cout << endl;
		}
		cout << endl;*/
		//cout << start.row << " " << start.col << endl;
		/*for (auto& x : nodes)
		{
		cout << x.row << " " << x.col << endl;
		}*/
		upgrade_plan(_costs, nodes, start);
		QTableWidgetItem* ptw = nullptr;
		for (int i = 0; i < s_r; i++)
		{
			tb.insertRow(i);
			for (int j = 0; j < s_c; j++)
			{
				if (_costs[i][j].second == -1)
				{
					ptw = new QTableWidgetItem(QString::number(0));
					tb.setItem(i, j,ptw);
					continue;
				}
				ptw = new QTableWidgetItem(QString::number(_costs[i][j].second));
				tb.setItem(i, j, ptw);
			}
		
		}
	
	}
}

inline double func_value(Costs& _costs, int s_r, int s_c)
{
	double result = 0;
	for (int i = 0; i < s_r; i++)
	{
		for (int j = 0; j < s_c; j++)
		{
			if (_costs[i][j].second != -1)
			{
				result += _costs[i][j].second*_costs[i][j].first;
			}
		}
	}
	return result;
}

class CourseWork : public QWidget
{
	Q_OBJECT
public:
	CourseWork(QWidget *parent = 0);
	~CourseWork();

private:
	Ui::CourseWorkClass ui;
	// Динамическое программирование
	 int N = 12;
	 double h = 0.1;
	 double B = 30;
	 double y1 = 0;
	 int size = static_cast<int>(B / h + 0.05);
	 double eps = 0.00001;

	vector<double>y_set;
	vector<double>x_set;
	double y_last;
	vector_table tables;

	vector<double> heft = { 0.9,1.5,1,0.7,1.2,3.6,0.8,3,1.9,2,3.1,1 };
	vector<double>probob = { 0.1,0.05,0.15,0.3,0.03,0.7,0.07,0.2,0.12,0.2,0.06,0.08 };
	vector<int>counters = { 1,2,3,4,6,7,5,4,3,1,4,10 };

	// Сетевая задача

	int p = 7;
	int c = 8;
	Costs costs;
	PCType produs;
	PCType cons;
	fstream fl;


public slots:


};

#endif // COURSEWORK_H
