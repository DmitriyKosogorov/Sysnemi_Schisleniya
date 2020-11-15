#include<iostream>
#include "System.h"
#include<string>
#include<algorithm>
typedef long long myclass;

using namespace std;




int value_out(char c)
{
	switch (c)
	{
	case '1': return(1);
	case '2': return(2);
	case '3': return(3);
	case '4': return(4);
	case '5': return(5);
	case '6': return(6);
	case '7': return(7);
	case '8': return(8);
	case '9': return(9);
	case 'A': return(10);
	case 'B': return(11);
	case 'C': return(12);
	case 'D': return(13);
	case 'E': return(14);
	case 'F': return(15);
	case 'G': return(16);
	case 'H': return(17);
	case 'I': return(18);
	case 'J': return(19);
	case 'K': return(20);
	case 'L': return(21);
	case 'M': return(22);
	case 'N': return(23);
	case 'O': return(24);
	case 'P': return(25);
	case 'Q': return(26);
	case 'R': return(27);
	case 'S': return(28);
	case 'T': return(29);
	case 'U': return(30);
	case 'V': return(31);
	case 'W': return(32);
	case 'X': return(33);
	case 'Y': return(34);
	case 'Z': return(35);
	default: return(0);
	}
}
char value_in(int c)
{
	switch (c)
	{
	case 1: return('1');
	case 2: return('2');
	case 3: return('3');
	case 4: return('4');
	case 5: return('5');
	case 6: return('6');
	case 7: return('7');
	case 8: return('8');
	case 9: return('9');
	case 10: return('A');
	case 11: return('B');
	case 12: return('C');
	case 13: return('D');
	case 14: return('E');
	case 15: return('F');
	case 16: return('G');
	case 17: return('H');
	case 18: return('I');
	case 19: return('J');
	case 20: return('K');
	case 21: return('L');
	case 22: return('M');
	case 23: return('N');
	case 24: return('O');
	case 25: return('P');
	case 26: return('Q');
	case 27: return('R');
	case 28: return('S');
	case 29: return('T');
	case 30: return('U');
	case 31: return('V');
	case 32: return('W');
	case 33: return('X');
	case 34: return('Y');
	case 35: return('Z');
	default: return(0);
	}
}




System::System()
{
	data = BASE_VALUE-'0';
	base = BASE_SYSTEM;
}
System::System(myclass znach)
{
	char c;
	while (znach > 0)
	{
		c = (znach % 10) - '0';
		data = c + data;
		znach = znach / 10;
	}
	data = znach;
	base = BASE_SYSTEM;
}
System::System(myclass znach, myclass syst)
{
	char c;
	while (znach > 0)
	{
		c = (znach % 10) + 48;
		data = c + data;
		znach = znach / 10;
	}
	base = syst;
}

myclass System::getData()
{
	myclass result=0;
	int a = 1,b;
	char g;
	for (int i = data.length(); i >= 0; i--)
	{
		g = data[i];
		b = value_out(g) * a;
		result = result + b;
		a = a * base;
	}
	return(result);
}

void System::changeBase(myclass new_syst)
{
	int i = 0, a,k;
	myclass sum = 0;
	for(int i=data.length()-1;i>=0;i--)
	{
		a = 1;
		for(int j=data.length()-1;j>i;j--)
		{
			a = a * base;
		}
		k = (data[i] - 48) * a;
		sum = sum + k;
	}
	base = new_syst;
	a = 1;
	data = "";
	while (sum > 0)
	{
		data = ((char)(sum % base+48))+data;
		a = a * 10;
		sum = sum / base;
	}
}

void System::clear()
{
	data = "0";
	base = 0;
}

System System::operator+(const System& elem)
{
	System tryn(0, 10);
	tryn.data = this->data;
	tryn.base = this->base;
	int a = 1,k=0,i;
	char first, second;
	tryn.changeBase(elem.base);
	System maxx(0, elem.base),minn(0, elem.base);
	if (tryn.data.length() >= elem.data.length())
	{
		maxx.data = "0"+tryn.data;
		minn.data = "0"+elem.data;
	}
	else 
	{
		maxx.data = "0"+elem.data;
		minn.data = "0"+tryn.data;
	}


	for (i = 0; i < maxx.data.length() - minn.data.length(); i++)
		minn.data = "0" + minn.data;


	string result = "";
	for(i=maxx.data.length()-1;i>=0;i--)
	{
		first = maxx.data[i];
		second = minn.data[i];
		if (value_out(first)+value_out(second) + k >= maxx.base)
		{
			result = ((char)(value_out(first) + value_out(second) + k - maxx.base+48))+result;
			k = 1;
		}
		else
		{
			result = ((char)(value_out(first) + value_out(second) + k+48)) + result;
			k = 0;
		}
	}
	if (result[0] == '0')
		result.erase(0, 1);
	tryn.data = result;
	return tryn;
}


System System::operator-(const System& elem)
{
	System tryn(0, 10);
	tryn.data = this->data;
	tryn.base = this->base;
	int a = 1, k = 0, i;
	char first, second;
	tryn.changeBase(elem.base);
	System maxx(0, elem.base), minn(0, elem.base);
	if (tryn.data.length() >= elem.data.length())
	{
		maxx.data = tryn.data;
		minn.data = elem.data;
	}
	else
	{
		maxx.data = elem.data;
		minn.data = tryn.data;
	}


	for (i = 0; i < maxx.data.length() - minn.data.length(); i++)
		minn.data = "0" + minn.data;


	string result = "";
	for (i = maxx.data.length() - 1; i >= 0; i--)
	{
		first = maxx.data[i];
		second = minn.data[i];
		if (value_out(first) - value_out(second) + k < 0)
		{
			result = ((char)(value_out(first) - value_out(second) + k + maxx.base + 48)) + result;
			k = -1;
		}
		else
		{
			result = ((char)(value_out(first) - value_out(second) + k + 48)) + result;
			k = 0;
		}
	}
	tryn.data = result;
	return tryn;
}
void System::operator=(const System& elem)
{
	this->data = elem.data;
	this->base = elem.base;
}
bool System::operator==(const System& elem)
{
	System save;
	save.data = this->data;
	save.base = this->base;
	save.changeBase(elem.base);
	return(elem.data == save.data);
}
bool System::operator!=(const System& elem)
{
	System save;
	save.data = this->data;
	save.base = this->base;
	save.changeBase(elem.base);
	return(elem.data != save.data);
}

ostream& operator<<(ostream& out, const System& elem)
{
	out << elem.data << "(" << elem.base << ")";
	return out;
}
