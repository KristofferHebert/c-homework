#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    string toDec = "";
    string beenDec = "";
    vector<char> normalV(26);
    vector<char> cipherV(26);

    cipherV.at(0) = '!'; 
    cipherV.at(1) = '^'; 
    cipherV.at(2) = '&'; 
    cipherV.at(3) = '*'; 
    cipherV.at(4) = '@'; 
    cipherV.at(5) = '('; 
    cipherV.at(6) = ')'; 
    cipherV.at(7) = '­-'; 
    cipherV.at(8) = '#'; 
    cipherV.at(9) = '_'; 
    cipherV.at(10) = '='; 
    cipherV.at(11) = '+'; 
    cipherV.at(12) = '['; 
    cipherV.at(13) = '{'; 
    cipherV.at(14) = '$'; 
    cipherV.at(15) = ']'; 
    cipherV.at(16) = '}'; 
    cipherV.at(17) = ';'; 
    cipherV.at(18) = ':'; 
    cipherV.at(19) = ','; 
    cipherV.at(20) = '%'; 
    cipherV.at(21) = '<'; 
    cipherV.at(22) = '.'; 
    cipherV.at(23) = '>'; 
    cipherV.at(24) = '/'; 
    cipherV.at(25) = '?'; 

    normalV.at(0) = 'a'; 
    normalV.at(1) = 'b'; 
    normalV.at(2) = 'c'; 
    normalV.at(3) = 'd'; 
    normalV.at(4) = 'e'; 
    normalV.at(5) = 'f'; 
    normalV.at(6) = 'g'; 
    normalV.at(7) = '­h'; 
    normalV.at(8) = 'i'; 
    normalV.at(9) = 'j'; 
    normalV.at(10) = 'k'; 
    normalV.at(11) = 'l'; 
    normalV.at(12) = 'm'; 
    normalV.at(13) = 'n'; 
    normalV.at(14) = 'o'; 
    normalV.at(15) = 'p'; 
    normalV.at(16) = 'q'; 
    normalV.at(17) = 'r'; 
    normalV.at(18) = 's'; 
    normalV.at(19) = 't'; 
    normalV.at(20) = 'u'; 
    normalV.at(21) = 'v'; 
    normalV.at(22) = 'w'; 
    normalV.at(23) = 'x'; 
    normalV.at(24) = 'y'; 
    normalV.at(25) = 'z'; 

    // Gather secret message from user
    cout << "Enter a secret message: ";
    getline(cin, toDec);

    // Loop over each char in message
    for(int i = 0; i < toDec.length(); i++){
        
        // Loop over cypher and find pair
        for(int ii = 0; ii < 26; ii++){
            // Decrypt secret message
            if (toDec.at(i) == cipherV.at(ii)) {
                beenDec+=normalV.at(ii);
            }
        }

    }

    // Print message
    cout << "Decrypted message: " << beenDec << endl;
    
    return 0;
}
