#pragma once
#ifndef System_H
#define System_H
typedef long long myclass;
using namespace std;

const int BASE_SYSTEM = 36;
const int BASE_VALUE = 0;

int value_out(char c);
char value_in(int c);

class SystemException {};
class System
{
private:
	string data;
	int base;

public:
	System();
	System(myclass znach);
	System(myclass znach, myclass syst);
	myclass getData();
	void changeBase(myclass new_syst);
	void clear();
	System operator+(const System& elem);
	System operator-(const System& elem);
	void operator=(const System& elem);
	bool operator==(const System& elem);
	bool operator!=(const System& elem);
	friend ostream& operator<<(ostream& out, const System& elem);

};
#endif
