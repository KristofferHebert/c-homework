#include <iostream>
#include <string>
using namespace std;

int main() {
    // Gather tweet from user input
    string tweet;
    int pos;
    cout << "Enter tweet: ";
    getline(cin, tweet);
    
    // Truncate tweet to 160 chars
    tweet.resize(160);

    // Show truncated tweet
    cout << tweet <<endl;

    // Find ABBR in tweet and display translation.
    if( tweet.find("LOL") != -1){
        pos = tweet.find("LOL");
        tweet.replace(pos, 3, "laughing out loud");
    } 
    if(tweet.find("IRL") != -1){
        pos = tweet.find("IRL");
        tweet.replace(pos, 3, "in real life");         
    } 
    if(tweet.find("AFK") != -1){ 
        pos = tweet.find("AFK");
        tweet.replace(pos, 3, "away from keyboard");         
    } 
    if(tweet.find("NVM") != -1){  
        pos = tweet.find("NVM");
        tweet.replace(pos, 3, "never mind");
    } 
    if(tweet.find("BFF") != -1){ 
        pos = tweet.find("BFF");
        tweet.replace(pos, 3, "best friends forever");        
    } 
    if(tweet.find("FTW") != -1){
        pos = tweet.find("FTW");
        tweet.replace(pos, 3, "for the win");        
    } 
    if(tweet.find("IIRC") != -1){ 
        pos = tweet.find("IIRC");
        tweet.replace(pos, 4, "if I recall correctly");        
    } 
    if(tweet.find("TTYL") != -1){ 
        pos = tweet.find("TTYL");
        tweet.replace(pos, 4, "talk to you later");        
    } 
    if(tweet.find("IMHO") != -1){ 
        pos = tweet.find("IMHO");
        tweet.replace(pos, 4, "in my humble opinion");  
    } 

    // Display tweet with translated ABBR
    cout << tweet << endl;   
}