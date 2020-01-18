#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int* arr, int length) {
	int temp = 0;
	for (int j = length - 1; j >= 0; j--) {
		if (arr[j] < arr[j - 1]) {
			for (int i = 0; i < j; i++) {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}
}

void output(int arr[], int length) {
	for (int k = 0; k < length; k++) {
		std::cout << arr[k] << " ";
	}
}


int main() {
	setlocale(LC_ALL, "russian");
	int length;
	std::cout << "Введите количество элементов" << std::endl;
	std::cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		std::cin >> arr[i];
	}
	bubble(arr, length);
	output(arr, length);
	return 0;
}