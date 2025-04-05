/*Binary String to Number
Given a binary string as input, convert into its decimal form and return it as an integer.

Input Format

In the function a binary string is passed.

Output Format

Return an integer.



Sample Input

111


Sample Output

7*/

#include <iostream>
#include <string>
#include<cmath>
using namespace std;
 
int binaryToDecimal(string s)
{
    // your code goes here
    int output = 0;
    
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '1'){
            output = output + pow(2,s.size() - i - 1); //going from right to left
        }
    }
    return output;
    
}


int main(){
    string binary;

    cout << "enter the binary string" << endl;

    getline(cin,binary,'\n');

    cout<< binaryToDecimal(binary);
}