#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <cstring>

size_t strlena(const char* string) {
	int counter = 0;
	while (string[counter] != '\0') {
		counter++;
	}
	return counter;
}
int strcmpa(const char* string1, const char* string2) {
	int i = 0;
	while (string1[i] != '\0' || string2[i] != '\0') {
		if (string1[i] > string2[i]) {
			return 1;
		}
		else if (string1[i] < string2[i]) {
			return -1;
		}
		i++;
	};
	return 0;
}
char* strstra(char* string1, const char* string2) {
	for (int i = 0; i < strlen(string1); i++) {
		int counter = 0;
		int j = 0;
		while (string1[i+j] == string2[j]) {
			counter++;
			j++;
			if (counter == strlen(string2)) {
				return &string1[i];
			}
		}
	}
	return nullptr;
} 
char* strcata(char* destptr, const char* srcptr) {
	int len1 = strlen(destptr);
	int len2 = strlen(srcptr);
	for (int i = 0; i < len2; i++) {
		destptr[len1+i] = srcptr[i];
	}
	destptr[len1 + len2] = '\0';
	return destptr;
}

int main() {
	setlocale(LC_ALL, "russian");
	char str1[51], str2[51];
	std::cin.getline(str1, sizeof(str1));
	std::cin.getline(str2, sizeof(str2));
	std::cout << strlena(str1) << " " << strlena(str2) << std::endl;

	if(strcmpa(str1, str2)==1){
		std::cout << "1 строка больше 2" << std::endl;
	}else if(strcmpa(str1,str2)==-1){
		std::cout << "2 строка больше 1" << std::endl;
	}else if(strcmpa(str1,str2)==0){
		std::cout << "Строки равны" << std::endl;
	}
	char* strhelp = strstra(str1, str2);
	if (strstra(str1, str2) == nullptr) {
		std::cout << "-1" << std::endl;
	}
	else {
		std::cout <<(int)strhelp-(int)str1 << std::endl;
	}
	std::cout << strcata(str1, str2); 
	return 0;
}