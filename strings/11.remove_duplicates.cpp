/*Remove Duplicates
Given a string S, the task is to remove all the duplicates from the given string

and return the updated string in sorted order.

Input Format

In the function a string is passed.

Output Format

Return the updated string.



Sample Input

string s = "geeksforgeeks"


Sample Output

"efgkors"*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


string removeDuplicate(string s){
    // your code goes here
    sort(s.begin(),s.end());
    string output="";
    output = s[0];
    for(int i = 0; i<s.size(); i++){
        if(s[i] != s[i+1] && s[i+1]!='\0'){
            output += s[i+1];
        }
    }
    return output;
}

int main(){
    cout << "enter the string" << endl;
    string input;
    getline(cin,input,'\n');

    string output = removeDuplicate(input);
    cout << output << endl;
}