#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

struct Titanic {
    int psgr_id;
    int survival;
    int pclass;
    std::string name;
    std::string sex;
    int age;
    int sibsp;
    int parch;
    std::string ticket;
    double fare;
    std::string cabin;
    std::string embarked;
};

Titanic parseStr(std::string const &psger) {
    Titanic passenger;
    std::stringstream psgr(psger);
    std::string psgr_id, survival, pclass,temp,name,sex,age,sibsp,parch,ticket,fare,cabin,embarked;
    std::getline(psgr, psgr_id, ',');
    std::getline(psgr, survival, ',');
    std::getline(psgr, pclass, ',');
    std::getline(psgr, temp, '"');
    std::getline(psgr, name, '"');
    std::getline(psgr, temp, ',');
    std::getline(psgr, sex, ',');
    std::getline(psgr, age, ',');
    std::getline(psgr, sibsp, ',');
    std::getline(psgr, parch, ',');
    std::getline(psgr, ticket, ',');
    std::getline(psgr, fare, ',');
    std::getline(psgr, cabin, ',');
    std::getline(psgr, embarked, ',');
    passenger.psgr_id = std::stoi(psgr_id);
    passenger.survival = std::stoi(survival);
    passenger.pclass = std::stoi(pclass);
    passenger.name = name;
    passenger.sex = sex;
    if (age.length() > 0) {
        passenger.age = std::stoi(age);
    }
    else {
        passenger.age = -1;
    }
    passenger.sibsp = std::stoi(sibsp);
    passenger.parch = std::stoi(parch);
    passenger.ticket = ticket;
    passenger.fare = std::stod(fare);
    passenger.cabin = cabin;
    passenger.embarked = embarked;
    return passenger;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Titanic> passengers;
    std::string path = "C:/Users/Arthur/Documents/Programming/KFU/lab_5/train.csv";

    std::ifstream fin;

    fin.open(path);

    if (!fin.is_open()) {
        std::cout << "Error while opening file" << std::endl;
    }
    else {
        std::string str;
        std::getline(fin, str, '\r');
        while (!fin.eof()) {
            std::string str;
            std::getline(fin, str, '\r');
            Titanic passenger = parseStr(str);
            passengers.push_back(passenger);
        }
    }
    int survived = 0, survived_1 = 0, survived_2 = 0, survived_3 = 0, survived_w = 0, survived_m = 0, s = 0, c = 0, q = 0, man = 0, women = 0, total=0;
    int avg_pas, avg_wom, avg_man;
    std::vector<int> underage;
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers[i].age > -1) {
            avg_pas+=passengers[i].age;
            total++;
            if (passengers[i].age < 18) {
                underage.push_back(passengers[i].psgr_id);
            }
        }
        if (passengers[i].survival == 1) {
            survived++;
        }
        if (passengers[i].survival == 1 && passengers[i].pclass == 1) {
            survived_1++;
        }
        if (passengers[i].survival == 1 && passengers[i].pclass == 2) {
            survived_2++;
        }
        if (passengers[i].survival == 1 && passengers[i].pclass == 3) {
            survived_3++;
        }
        if (passengers[i].sex == "female") {
            if (passengers[i].age > -1) {
                avg_wom += passengers[i].age;
                women++;
            }
            if (passengers[i].survival == 1) {
                survived_w++;
            }
        }
        if (passengers[i].sex == "male") {
            if (passengers[i].age > -1) {
                avg_man += passengers[i].age;
                man++;
            }
            if (passengers[i].survival == 1) {
                survived_m++;
            }
        }
        if (passengers[i].embarked == "C") {
            c++;
        }
        if (passengers[i].embarked == "S") {
            s++;
        }
        if (passengers[i].embarked == "Q") {
            q++;
        }
    }
    avg_pas /= total;
    avg_man /= man;
    avg_wom /= women;
    std::string path_2 = "C:/Users/Arthur/Documents/Programming/KFU/lab_5/output.txt";
    std::ofstream fout(path_2);
    if(!fout){
        std::cout << "Error!" << std::endl;
    }else{
        fout << "Survived: " << survived << "\n";
        fout << "Survived 1 class: " << survived_1 << "\n";
        fout << "Survived 2 class: " << survived_2 << "\n";
        fout << "Survived 3 class: " << survived_3 << "\n";
        fout << "Woman survived : " << survived_w << "\n";
        fout << "Man survived: " << survived_m << "\n";
        fout << "Passenger's avg age: " << avg_pas << "\n";
        fout << "Man's avg age: " << avg_man << "\n";
        fout << "Woman's avg age: " << avg_wom << "\n";
        fout << "Underage people id's: ";
        for(size_t i=0;i<underage.size(); i++){
            fout << underage[i] << ", ";
        }
        fout << "\nMost people from state: ";
        if(q>=s && q>=c){
            fout << "Queenstown" << "\n";
        }else if(s>=q && s>=c){
            fout << "Southampton" << "\n";
        }else if(c>=q && c>=s){
            fout << "Cherbourg" << "\n";
        }
    }
    fout.close();
    fin.close();
    return 0;
}
