//instead of reading the sentence one by one we can read the entire sentence

#include <iostream>
using namespace std;

int main(){
    char paragraph[1000];
    cin.getline(paragraph,15, '.'); // means the input given is stored in paragraph array
    //input can be maximum of 15 words and it is terminated when '.' is encountered
    // by default \n is used to terminate
    cout << paragraph << endl;
}