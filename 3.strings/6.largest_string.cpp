#include <iostream>
#include <cstring>
using namespace std;

//problem: Read N strings and print the largest string. Each string can have upto 1000 chars.

int main(){

    int n;
    cin >> n;

    cin.get(); // it is there to consume the \n which comes when we input n and press enter.

    char sentence[1000];
    char largest[1000];

    int largest_len = 0;

    while(n--){
        cin.getline(sentence,1000);
        int len = strlen(sentence);
        if(len > largest_len){
            largest_len = len;
            strcpy(largest,sentence);
        }
    }
    cout << "Largest sentence is: " << largest << endl;
    return 0;
}