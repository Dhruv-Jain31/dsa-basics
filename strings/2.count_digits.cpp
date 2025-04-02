#include<iostream>
using namespace std;

int main(){
    //store and then count
    // read one by one and then count

    char ch;
    ch = cin.get();

    //count
    int alpha = 0;
    int space = 0;
    int digit = 0;

    while(ch!='\n'){
        if(ch >= '0' && ch <= '9'){
            digit++;
        }
        else if((ch >= 'a' && ch<='z') || (ch>='A' && ch <= 'Z')){
            alpha++;
        }
        else if(ch==' ' || ch == '\t'){
            space++;
        }
        ch = cin.get();
    }
    cout << "Total Alphabets " << alpha << endl;
    cout << "Total Digits " << digit << endl;
    cout << "Total space " << space << endl;

    return 0;
}