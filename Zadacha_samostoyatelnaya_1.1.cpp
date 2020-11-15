#include<iostream>
#include"system.cpp"
using namespace std;
int main()
{
	System a(123,8),b(28,10);
	cout << a<<endl;
	a.changeBase(2);
	cout <<a<<"+"<<b<<"="<<a + b<<endl;
	cout << a << "-" << b << "=" << a - b<<endl;
	cout << a << "==" << b <<": "<< (a == b)<<endl;
	cout << a << "!=" << b << ": " << (a != b);
	return 0;
}
