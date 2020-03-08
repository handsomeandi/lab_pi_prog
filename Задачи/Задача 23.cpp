#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <cstring>

bool valid(char symb) {
	int s = (int)symb;
	if ((symb >= 48 && symb <= 57) || (symb >= 65 && symb <= 90) || (symb >= 97 && symb <= 122)) {
		return true;
	}
	else {
		return false;
	}
}

bool isPalindrome(char string[]) {
	int k = 0;
	bool flag = true;
	for (int i = 20; i >= 0; i--) {
		if (!string[i]) {
			continue;
		}
		else {
			for (i; i > (i + 1) / 2; i--) {
				int symb = (int)string[i];
				if (valid(symb)) {
					if (::tolower(string[k]) == ::tolower(string[i])) {
						k++;
					}
					else {
						flag = false;
						break;
					}
				}
				else {
					continue;
				}
			}
		}
	}
	if (flag) { std::cout << "Palindrom"; return true; }
	else { std::cout << "Not a palindrom"; return false; }

}


int main() {
	setlocale(LC_ALL, "russian");
	char string[21] = { 0 };
	std::cin.getline(string, sizeof(string));
	isPalindrome(string);
	return 0;
}