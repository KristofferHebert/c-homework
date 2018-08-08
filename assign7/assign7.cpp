#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.h" 

using namespace std;

// Get a filename from program arguments, then make a Person for each line in the file.
bool ReadPeopleFromFile(int argc, char* argv[], vector<Person> &people) {
    Person tmpPrsn;
    ifstream inFS;
    int tmpAge = 0;
    string tmpGender = "";
    int tmpYI = 0;
    
    if (argc != 2) {
        cout << "\nUsage: [EXECUTABLE FILE] [TEXT DATA FILE], e.g. myprog.exe dev_people.txt" << endl;
        return true; // indicates error
    }
    
    cout << "Opening file " << argv[1] << ".\n";
    inFS.open(argv[1]); // Try to open file
    if (!inFS.is_open()) {
        cout << "Could not open file " << argv[1] << ".\n";
        return true; // indicates error
    }
    
    while (!inFS.eof()) {
        inFS >> tmpAge;
        inFS >> tmpGender;
        inFS >> tmpYI;
        tmpPrsn.SetData(tmpAge, tmpGender, tmpYI); // FIXME Also set gender and yearly income
        tmpPrsn.Print();
        people.push_back(tmpPrsn);
    }
    inFS.close();
    cout << "Finished reading file." << endl;
    
    return false; // indicates no error
}

// Ask user to enter person values.
void GetUserInput(int &ageLowerRange, int&ageUpperRange, string&gender, int&yILowerRange, int&yIUpperRange) {
    
    cout<<"\nEnter lower range of age: ";
    cin >> ageLowerRange;
    
    cout << "Enter upper range of age: ";
    cin >> ageUpperRange;

    cout << "Enter gender (male, female, or any): ";
    cin >> gender;

    cout << "Enter lower range of income: ";
    cin >> yILowerRange;

    cout << "Enter upper range of income: ";
    cin >> yIUpperRange;   

    return;
}

// Return people within the given age range.
vector<Person> GetPeopleInAgeRange(vector<Person> ppl, int lowerRange, int upperRange) {
    unsigned int i = 0;
    
    vector<Person> pplInAgeRange;
    int age = 0;
    for (i = 0; i < ppl.size(); ++i) {
        age = ppl.at(i).GetAge();
        if ((age >= lowerRange) && (age <= upperRange)) {
            pplInAgeRange.push_back(ppl.at(i));
        }
    }
    
    return pplInAgeRange;
}

vector<Person> GetPeopleWithSpecificGender(vector<Person> ppl, string requestedGender) {
    unsigned int i = 0;
    
    vector<Person> pplWithSpecificGender;
    string gender;
    for (i = 0; i < ppl.size(); ++i) {
        gender = ppl.at(i).GetGender();
        if (requestedGender == "any"){
            pplWithSpecificGender.push_back(ppl.at(i));
        }
        else if (gender == requestedGender) {
            pplWithSpecificGender.push_back(ppl.at(i));
        }
    }
    
    return pplWithSpecificGender;
}

vector<Person> GetPeopleInIncomeRange(vector<Person> ppl, int lowerRange, int upperRange) {
    unsigned int i = 0;
    
    vector<Person> pplIncomeRange;
    int income = 0;
    for (i = 0; i < ppl.size(); ++i) {
        income = ppl.at(i).GetIncome();
        if ((income >= lowerRange) && (income <= upperRange)) {
            pplIncomeRange.push_back(ppl.at(i));
        }
    }
    
    return pplIncomeRange;
}

int main(int argc, char* argv[]) {
    vector<Person>people;
    bool hadError = false;
    int ageLowerRange = 0;
    int ageUpperRange = 0;
    string gender = "";
    int yILowerRange = 0;
    int yIUpperRange = 0;

    hadError = ReadPeopleFromFile(argc, argv, people);
    if( hadError ) {
        return 1; // indicates error
    }
    
    GetUserInput(ageLowerRange, ageUpperRange, gender, yILowerRange, yIUpperRange);
    people = GetPeopleInAgeRange(people, ageLowerRange, ageUpperRange);
    people = GetPeopleWithSpecificGender(people, gender);
    people = GetPeopleInIncomeRange(people, yILowerRange, yIUpperRange);

    cout<<"\nNumberofpotentialcustomers="<<people.size()<<endl;    
    
    return 0;
}
