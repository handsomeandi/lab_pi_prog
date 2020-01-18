#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <vector>
#include <algorithm>


void swap(int* a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int msort(int* a, int* b, int* c) {
	if (*a > * b)swap(a, b);
	if (*b > * c)swap(b, c);
	if (*c < * a)swap(c, a);
	return	*c;
}

void info(const int*a) {
	std::cout << "Адрес: " << a << std::endl;
	std::cout << "Значение: " << *a << std::endl;
}

int* add(int* a, const int*b) {
	*a = *b + *a;
	return a;
}

int main() {
	setlocale(LC_ALL, "russian");
	int a = 5, b = 7, c = 6;
	info(&a);
	info(&b);
	info(&c);
	std::cout << "Максимум: " << msort(&a, &b, &c) << std::endl;
	info(add(&a, add(&b, &c)));
	return 0;
}