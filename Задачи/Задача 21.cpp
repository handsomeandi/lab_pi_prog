#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits>


int main() {
	setlocale(LC_ALL, "russian");
	int masiv[8][10];
	bool start = true;
	int tries = 5;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			masiv[i][j] = 0;
		}
	}
	srand(time(0));
	int row = 0 + rand() % 10;
	int col = 0 + rand() % 8;
	masiv[col][row] = 2;
	std::cout << col << row << std::endl; 
	while (start) {
		int colg, rowg;
		if (tries < 1) {
			start = false;
			break;
		}
		else {
			std::cout << "Введите координаты ячейки" << std::endl;
			std::cin >> colg >> rowg;
			if (masiv[colg][rowg] == 2) {
				std::cout << "Вы угадали" << std::endl;
				break;
			}
			else if (masiv[colg][rowg] == 3) {
				std::cout << "Вы уже вводили эти координаты" << std::endl;
				continue;
			}
			else if (colg > 7 || colg < 0 || rowg>9 || rowg < 0) {
				std::cout << "Вы ввели неверные значения ячейки" << std::endl;
				continue;
			}
			else {
				masiv[colg][rowg] = 3;
				tries--;
			}
		}
	}
	std::cout << "Вы проиграли.";
	return 0;
}