#include <iostream>
#include <string>
using namespace std;

int main() {
    // Gather tweet from user input
    string tweet;
    cout << "Enter tweet: ";
    getline(cin, tweet);
    
    // Truncate tweet to 160 chars
    tweet.resize(160);

    // Show truncated tweet
    cout << tweet <<endl;

    // Find ABBR in tweet and display translation.
    if( tweet.find("LOL") != -1){ 
        cout << "LOL = laughing out loud" <<endl;
    } 
    if(tweet.find("IRL") != -1){ 
        cout << "IRL = in real life" <<aendl;
    } 
    if(tweet.find("AFK") != -1){ 
        cout << "AFK = away from keyboard" <<endl;
    } 
    if(tweet.find("NVM") != -1){  
        cout << "NVM = never mind" <<endl;
    } 
    if(tweet.find("BFF") != -1){ 
        cout << "BFF = best friends forever" <<endl;
    } 
    if(tweet.find("FTW") != -1){
        cout << "FTW = for the win" <<endl;
    } 
    if(tweet.find("IIRC") != -1){ 
        cout << "IIRC = if I recall correctly" <<endl;
    } 
    if(tweet.find("TTYL") != -1){ 
        cout << "TTYL = talk to you later" <<endl;
    } 
    if(tweet.find("IMHO") != -1){ 
        cout << "IMHO = in my humble opinion" <<endl;
    } 
}