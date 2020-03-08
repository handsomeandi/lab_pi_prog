#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <vector>
#include <algorithm>

double BMI(double weight, double height) {
	double index = weight / ((height / 100) * (height / 100));
	return index;
}

void printBMI(double BMI) {
	if (BMI<18.5) {
		std::cout << "Underweight" << std::endl;
	}
	else if (BMI >= 18.5 && BMI < 25.0) {
		std::cout << "Normal weight" << std::endl;
	}
	else if (BMI >= 25.0 && BMI < 30.0) {
		std::cout << "Overweight" << std::endl;
	}
	else {
		std::cout << "Obesity" << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	double weight, height;
	std::cout << "Введите вес, рост" << std::endl;
	std::cin >> weight >> height;
	printBMI(BMI(weight, height));
	return 0;
}