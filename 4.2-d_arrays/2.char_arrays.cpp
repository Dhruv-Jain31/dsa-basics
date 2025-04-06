#include<iostream>
using namespace std;

int main(){
    char numbers[][10] = {
        "one",
        "two",
        "three",
        "forty",
        "eight",
        "hundred",
    };

    for(int i = 0; i < 6; i++){
        cout << numbers[i] << endl;
    } //print all the rows

    cout << numbers[2][2];

    return 0;
}