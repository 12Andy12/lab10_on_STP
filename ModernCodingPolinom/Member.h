#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Member
{
private:
	int cooef = 0;
	int degree = 1;

public:
	Member();
	Member(int new_cooef, int new_degree);
	int getCooef();
	int getDegree();
	void setCooef(int new_cooef);
	void setDegree(int new_degree);
	Member Diff();
	double calc(int x);
};

inline Member::Member() :cooef(), degree(1)
{
}

inline Member::Member(int new_cooef, int new_degree) : cooef(new_cooef), degree(new_degree)
{
}

inline int Member::getCooef()
{
	return cooef;
}

inline int Member::getDegree()
{
	return degree;
}

inline void Member::setCooef(int new_cooef)
{
	cooef = new_cooef;
}

inline void Member::setDegree(int new_degree)
{
	degree = new_degree;
}

inline Member Member::Diff()
{
	if (degree == 0)
		return Member(0, 0);
	return Member(cooef * degree, degree - 1);
}

inline double Member::calc(int x)
{
	return cooef * pow(x, degree);
}

inline string to_string(Member x)
{
	if (x.getDegree() == 1)
		return to_string(x.getCooef()) + "x";
	if (x.getDegree() == 0 and x.getCooef() == 0)
		return "";
	if (x.getDegree() == 0)
		return to_string(x.getCooef());
	return to_string(x.getCooef()) + "x^" + to_string(x.getDegree());
}

inline ostream& operator<<(ostream& out, Member a)
{
	out << to_string(a);
	return out;
}

inline bool operator==(Member a, Member b)
{
	return a.getDegree() == b.getDegree();
}

inline bool operator>(Member a, Member b)
{
	if (a.getDegree() > b.getDegree())
		return true;
	else if (a.getDegree() == b.getDegree() and a.getCooef() > b.getCooef())
		return true;
	else
		return false;
}

inline bool operator>=(Member a, Member b)
{
	if (a == b)
		return true;
	if (a > b)
		return true;
	return false;
}

inline bool operator<(Member a, Member b)
{
	if (a.getDegree() < b.getDegree())
		return true;
	else if (a.getDegree() == b.getDegree() and a.getCooef() < b.getCooef())
		return true;
	else
		return false;
}

inline bool operator<=(Member a, Member b)
{
	if (b == a)
		return true;
	if (b > a)
		return true;
	return false;
}
