#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int a;
	int b;
	double c;
	double d;
	int e;
	double f;
	cout << "Введите 2 числа" << endl;
	cin >> a;
	cin >> b;
	cout <<"(int, int)  Сумма:" << a + b << endl << "Разность:" << a - b << endl << "Произведение:" << a * b << endl << "Частное:" << a / b << endl;
	cout << "Введите 2 числа" << endl;
	cin >> c;
	cin >> d;
	cout << "(double, double)  Сумма:" << c + d << endl << "Разность:" << c - d << endl << "Произведение:" << c * d << endl << "Частное:" << c / d << endl;
	cout << "Введите 2 числа" << endl;
	cin >> e;
	cin >> f;
	cout << "(int,double)  Сумма:" << e + f << endl << "Разность:" << e - f << endl << "Произведение:" << e * f << endl << "Частное:" << e / f << endl;
	cout << "(double,int)  Сумма:" << f + e << endl << "Разность:" << f - e << endl << "Произведение:" << f * e << endl << "Частное:" << f / e << endl;
}