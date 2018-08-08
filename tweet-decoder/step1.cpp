#include <iostream>
#include <string>
using namespace std;

int main() {
   string tweet;
   string message;
   
   cout << "Enter abbreviation from tweet: ";
   cin >> tweet;
   
    // Output decoded abbreviation from tweet
    if( tweet == "LOL"){ 
        message = "LOL = laughing out loud";
    } else if(tweet == "IRL"){ 
        message = "IRL = in real life";
    } else if(tweet == "AFK"){ 
        message = "AFK = away from keyboard";
    } else if(tweet == "NVM"){  
        message = "NVM = never mind";
    } else if(tweet == "BFF"){ 
        message = "BFF = best friends forever";
    } else if(tweet == "FTW"){
        message = "FTW = for the win";
    } else if(tweet == "IIRC"){ 
        message = "IIRC = if I recall correctly";
    } else if(tweet == "TTYL"){ 
        message = "TTYL = talk to you later";
    } else if(tweet == "IMHO"){ 
        message = "IMHO = in my humble opinion";
    } else {
        message = "Sorry, don't know that one.";
    }

   cout << message << endl;
   
   return 0;
}
