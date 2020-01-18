#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <cstring>
#include <vector>

struct Student {
	char name[100];
	int group;
	int sec[5];
};

int main() {
	setlocale(LC_ALL, "russian");
	Student stud[10] = { "Pleb C.H.",1,{2,3,4,5,2},"Hleb C.P.",2,{2,4,4,5,4},"Gleb C.K.",3,{5,5,4,5,4},"Oleb C.R.",1,{2,3,5,5,2},"Pall K.N.",3,{4,4,4,5,4},
	"Tent F.O.",1,{2,3,3,5,2},"Jib I.R.",3,{1,4,4,3,4},"Pes C.M.",2,{5,5,5,5,4},"Kant M.H.",2,{2,3,4,3,2},"Rast T.P.",1,{5,4,4,5,4} };
	std::vector<Student> badg;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (stud[i].sec[j] < 3) {
				badg.push_back(stud[i]);
				break;
			}
		}
	}
	if (badg.size() > 0) {
		for (int i = 0; i < badg.size(); i++) {
			for (int j = 0; j < badg.size() - i - 1; j++) {
				if(badg[j].name[0]>badg[j+1].name[0]){
					Student temp = badg[j];
					badg[j] = badg[j + 1];
					badg[j + 1] = temp;
				}
			}
		}

		for (int i = 0; i < badg.size(); i++) {
			std::cout << badg[i].name << "	" << badg[i].group << std::endl;
		}
	}
	else {
		std::cout << "Not find" << std::endl;
	}
	return 0;
}