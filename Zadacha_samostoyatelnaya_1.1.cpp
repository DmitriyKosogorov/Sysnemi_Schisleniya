#include<iostream>
#include"system.cpp"
using namespace std;
System powe(System elem, System elem2)
{
	System tryn(0, 10), tryn1(0, 10);
	tryn = elem;
	tryn1 = elem;
	int n = elem2.getData();
	for (int i = 0; i < n; i++)
		tryn = tryn * tryn1;
	return tryn;
}
void sort(System* mas, int size)
{
	System tryn(0, 10);
	int i, j;
	for (i = 1; i < size; i++)
		for (j = 0; j <= i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				tryn = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = mas[i];
			}
		}

}
int main()
{
	System a(123,8),b(28,10);
	cout << a<<endl;
	//a.changeBase(10);
	cout <<a<<"+"<<b<<"="<<a + b<<endl;
	cout << a << "-" << b << "=" << a - b<<endl;
	cout << a << "*" << b << "=" << a * b << endl;
	cout << a << "/" << b << "=" << a / b << endl;
	cout << a << "==" << b <<": "<< (a == b)<<endl;
	cout << a << "!=" << b << ": " << (a != b)<<endl;
	cout << a << "<" << b << ": " << (a < b)<<endl;
	cout << a << ">" << b << ": " << (a > b) << endl;
	System c(2, 3), d(3, 10);
	cout << c << "^" << d << ": " << powe(c,d) << endl;
	System mas[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		System g(i*2, 35 - i);
		mas[i]=g;
		cout << mas[i] << endl;;
	}
	sort(mas, 10);
	for (i = 0; i < 10; i++)
	{
		cout << mas[i];
	}

	return 0;
}
