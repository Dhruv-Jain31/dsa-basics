/*Are Permutation
Given two strings A and B. Check if one string is permutation of the other.
A Permutation of a string is another string that contains same characters, only the order of characters can be different.
For example, “abcd” and “dabc” are Permutation of each other.

Input Format

In the function two strings passed.

Output Format

Return true if B is permutation of A else false.



Sample Input

string A = "test", B = "ttew"


Sample Output

false*/

#include<iostream>
#include<string>

using namespace std;

string string_sort(string str){
    //bubble sort for strings

    int n = str.size();
    for(int i = 0; i<n-1; i++){
        bool flag = false;
        for(int j = 0; j<n-i-1; j++){
            if(str[j] > str[j+1]){ //compares the string lexicogrphically
                flag = true;
                swap(str[j],str[j+1]);
            }
        }
        if(flag == false){
            break;
        }
    }
    return str;
}

bool arePermutation(string A, string B){
    A = string_sort(A);
    B = string_sort(B);

    if(A == B){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string A;
    string B;

    cout<< "enter string A :" << endl;

    getline(cin,A,'\n');

    cout << "enter string B :" << endl;

    getline(cin,B,'\n');

    bool permutation = arePermutation(A,B);

    cout<< permutation;

    return 0;
}