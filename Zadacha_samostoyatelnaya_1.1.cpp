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
	for (i = 1; i < size-1; i++)
		for (j = 0; j <= i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				tryn = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tryn;
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
	System mas[5];
	int i,size=5;
	for (i = 0; i < size; i++)
	{
		System g(200-6*i, 35 - i);
		mas[i]=g;
		cout << mas[i] << endl;;
	}
	sort(mas, size);
	for (i = 0; i < size; i++)
	{
		cout << mas[i];
	}

	return 0;
}
