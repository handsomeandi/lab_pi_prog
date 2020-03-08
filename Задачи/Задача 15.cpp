#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>


int main() {
	setlocale(LC_ALL, "russian");
	int n, counter,temp;
	counter = 0;
	std::cout << "Введите n" << std::endl;
	std::cin >> n;
	int* start = new int[n];
	std::cout << "Введите элементы массива" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> start[i];
		counter += 1;
		for (int i = 0; i < counter - 1; i++) {
			for (int j = 0; j < counter - 1 - i; j++) {
				if (start[j] > start[j + 1]) {
					temp = start[j];
					start[j] = start[j + 1];
					start[j + 1] = temp;
				}
			}
		}
		if (counter < 5) {
			for (int k = counter - 1; k >= 0; k--) {
				std::cout << start[k] << " ";
			}
		}
		else {
			for (int l = 4; l >= 0; l--) {
				std::cout << start[l] << " ";
			}
		}
		std::cout << std::endl;
	}
	return 0;
}