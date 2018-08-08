#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.h"

using namespace std;

// Constructor for the Person class.
Person::Person() {
    age = 0;
    gender = "default";
    yearlyIncome = 0;
    return;
}

// Print the Person class.
void Person::Print() {
    cout << "Age = " << this->age
         << ", gender = " << this->gender
         << ", yearly income = " << this->yearlyIncome
         << endl;
    return;
}

// Set the age, gender, and yearlyIncome of a Person.
void Person::SetData(int age, string gender, int yearlyIncome) {   // FIXME Also set gender and yearly income
    this->age = age;
    this->gender = gender;
    this->yearlyIncome = yearlyIncome;
    return;
}

// Get the age of a Person.
int Person::GetAge() {
    return this->age;
}

// Get the gender of a Person.
string Person::GetGender() {
    return this->gender;
}

// Get the gender of a Person.
int Person::GetIncome() {
    return this->yearlyIncome;
}