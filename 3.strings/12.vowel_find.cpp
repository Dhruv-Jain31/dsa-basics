/*Vowel Find
Given a string consisting of lowercase English alphabets, return a string containing all the vowels present in S in serial order.

Input Format

In the function a string S is passed.

Output Format

Return a string.



Sample Input

S = "aeoibsddaeioudb"


Sample Output

"aeoiaeiou"*/

#include<iostream>
#include<string>

using namespace std;

string vowel(string S){
    // your code goes here
    string output;
    for(int i = 0; i<S.size(); i++){
        if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u'){
            output += S[i];
        }
    }

    return output;

}

int main(){
    string S = "abdoeddnsaeoioaeoicn";
    S = vowel(S);
    cout << S;
}