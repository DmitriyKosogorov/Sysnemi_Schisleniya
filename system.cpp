#include<iostream>
#include "System.h"
#include<string>
#include<algorithm>
typedef long long myclass;

using namespace std;

System::System()
{
	data = BASE_VALUE;
	base = BASE_SYSTEM;
}
System::System(myclass znach)
{
	data = znach;
	base = BASE_SYSTEM;
}
System::System(myclass znach, myclass syst)
{
	data = znach;
	base = syst;
}



void System::changeBase(myclass new_syst)
{
	int i = 0, a, sum = 0;
	while (data > 0)
	{
		a = 1;
		for(int j=0;j<i;j++)
		{
			a = a * base;
		}
		i++;
		sum = sum + (data % 10) * a;
		data = data / 10;
	}
	base = new_syst;
	a = 1;
	while (sum > 0)
	{
		data = data+(sum % base)*a;
		a = a * 10;
		sum = sum / base;
	}
}

void System::clear()
{
	data = 0;
	base = 0;
}

System& System::operator+(const System& elem)
{
	System tryn(0, 10);
	tryn.data = this->data;
	tryn.base = this->base;
	int a = 1,k=0;
	tryn.changeBase(elem.base);
	System maxx(max(tryn.data, elem.data), elem.base), minn(min(tryn.data, elem.data), elem.base);
	myclass result = 0;
	while (maxx.data > 0)
	{
		if (maxx.data % 10 + minn.data % 10 + k >= maxx.base)
		{
			result = result + ((maxx.data % 10 + minn.data % 10 + k) - maxx.base) * a;
			k = 1;
		}
		else
		{
			result = result + (maxx.data % 10 + minn.data % 10 + k) * a;
			k = 0;
		}
		maxx.data = maxx.data / 10;
		minn.data = minn.data / 10;
	}
	this->data = result;
	this->base = tryn.base;
	return *this;
}



ostream& operator<<(ostream& out, const System& elem)
{
	out << elem.data << "(" << elem.base << ")";
	return out;
}
