#include<iostream>
#include <cstring>
using namespace std;

int main(){
    char a[1000] = "apple";
    char b[1000];

    //calc length
    cout<< strlen(a) << endl;

    //strcpy
    strcpy(b,a);
    cout<< b << endl;

    //compare
    cout << strcmp(a,b) << endl;

    //concat
    char web[] = "www.";
    char domain[] = "dhruv.com";

    cout << strcat(web,domain) << endl;

    //comparing again
    cout << strcmp(strcat(web,domain),b);
}