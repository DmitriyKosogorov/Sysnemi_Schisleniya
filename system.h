#pragma once
#ifndef System_H
#define System_H
typedef long long myclass;
using namespace std;

const int BASE_SYSTEM = 10;
const int BASE_VALUE = 0;

class SystemException {};
class System
{
private:
	int data;
	int base;

public:
	System();
	System(myclass znach);
	System(myclass znach, myclass syst);
	void changeBase(myclass new_syst);
	void clear();
	System& operator+(const System& elem);
	friend ostream& operator<<(ostream& out, const System& elem);

};
#endif
