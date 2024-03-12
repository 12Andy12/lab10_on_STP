#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "Member.h"

using namespace std;

class Polinom
{
private:
	set<Member> data;
public:
	Polinom();
	Polinom(int coeef, int degree);
	Polinom(Member first);
	Polinom(set<Member> newData);
	set<Member> getData();
	void add(Member newM);
	int getMaxDegree();
	int getCooef(int n);
	Member getElement(int n);
	void clear();
	Polinom operator+(Polinom a);
	Polinom operator-(Polinom a);
	Polinom operator*(Polinom a);
	Polinom diff();
	double calc(int x);
};

inline Polinom::Polinom() {}

inline Polinom::Polinom(int cooef, int degree)
{
	data.insert(Member(cooef, degree));
}

inline Polinom::Polinom(Member a)
{

	add(a);
}

inline Polinom::Polinom(set<Member> newData)
{
	for (auto i : newData)
	{
		add(i);
	}
}


inline set<Member> Polinom::getData()
{
	return data;
}

inline void Polinom::add(Member newM)
{
	Member id;
	bool isFind = false;
	for (auto i : data)
	{
		if (newM.getDegree() == i.getDegree())
		{
			id = i;
			isFind = true;
		}
	}
	if (isFind)
	{
		data.erase(id);
		data.insert(Member(id.getCooef() + newM.getCooef(), newM.getDegree()));
	}
	else
		data.insert(newM);
}


inline string to_string(Polinom x)
{
	string res = "";
	for (auto i : x.getData())
	{
		res += to_string(i) + " + ";
	}
	if (res == "")
		return res;
	res.pop_back();
	res.pop_back();
	res.pop_back();
	return res;
}

inline int Polinom::getMaxDegree()
{
	int m = 0;
	for (auto i : data)
		m = i.getDegree();
	return m;
}

inline Member Polinom::getElement(int n)
{
	Member m(0, 0);
	int j = 0;
	for (auto i : data)
	{
		if (j == n)
		{
			m.setDegree(i.getDegree());
			m.setCooef(i.getCooef());
			break;
		}
		++j;
	}
	return m;
}

inline int Polinom::getCooef(int n)
{
	int c = -1;
	for (auto i : data)
		if (i.getDegree() == n)
			c = i.getCooef();

	return c;
}

inline void Polinom::clear()
{
	data.clear();
}

inline Polinom Polinom::operator+(Polinom a)
{
	Polinom res;
	for (auto i : a.getData())
	{
		res.add(i);
	}
	for (auto i : data)
	{
		res.add(i);
	}
	return res;
}

inline Polinom Polinom::operator-(Polinom a)
{
	Polinom res;
	for (auto i : a.getData())
	{
		res.add(Member(-i.getCooef(), i.getDegree()));
	}
	for (auto i : data)
	{
		res.add(i);
	}
	return res;
}

inline Polinom Polinom::operator*(Polinom a)
{
	Polinom res;
	for (auto i : a.getData())
	{
		for (auto j : data)
		{
			res.add(Member(i.getCooef() * j.getCooef(), i.getDegree() + j.getDegree()));
		}
	}
	return res;
}

inline Polinom Polinom::diff()
{
	Polinom res;
	for (auto j : data)
	{
		Member a = j.Diff();
		if (a.getCooef() == 0 and a.getDegree() == 0)
			continue;
		res.add(a);
	}
	return res;
}

inline double Polinom::calc(int x)
{
	double res = 0;
	for (auto i : data)
	{
		res += i.calc(x);
	}
	return res;
}




