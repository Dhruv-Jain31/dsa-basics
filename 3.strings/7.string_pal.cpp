/*Check Palindrome
Given a string, write a c function to check if it is palindrome or not.

A string is said to be palindrome if reverse of the string is same as string. For example, “abba” is palindrome, but “abbc” is not palindrome.

Input Format

In the function a string is passed.

Output Format

Return true if it is palindrome else false.



Sample Input

abcdcba


Sample Output

true*/

#include <iostream>
#include <cstring> // for strlen and strcmp
#include <string> //for string class
using namespace std;

//palindrome using char array
bool isPalindromeCharArray(char str[]){
    int len = strlen(str);
    char rev[1000];

    //reversing the array
    for(int i = 0; i < len; i++){
        rev[i] = str[len - i - 1]; // since 0th index of rev is to be filled with last index of str.
    }
    rev[len] = '\0';

    if(strcmp(str,rev) == 0){
        return true;
    }
    else{
        return false;
    }
}

//checking palindrome using string
bool isPalindromeString(string str){
    int len = str.length();
    string rev = "";
    for(int i = len - 1; i >= 0; i--){
        rev = rev + str[i];
    }
    if(rev == str){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    // ------------ CHAR ARRAY VERSION ------------
    char charInput[1000];
    cout << "Enter a string (char array version): ";
    cin >> charInput;

    if (isPalindromeCharArray(charInput)) {
        cout << "It's a palindrome (char array) " << endl;
    } else {
        cout << "Not a palindrome (char array) " << endl;
    }

    // ------------ STRING VERSION ------------
    string strInput;
    cout << "\nEnter a string (string version): ";
    cin >> strInput;

    if (isPalindromeString(strInput)) {
        cout << "It's a palindrome (string) " << endl;
    } else {
        cout << "Not a palindrome (string) " << endl;
    }

    return 0;
}