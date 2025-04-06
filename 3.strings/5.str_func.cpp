#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[1000] = "apple";
    char b[1000];

    // Copy and compare
    strcpy(b, a);
    cout << "strcmp(a, b): " << strcmp(a, b) << endl;  // Should be 0

    // Ensuring var web has enough space for strcat: else modification will be done at unknown memory locations
    char web[1000] = "www.";
    char domain[] = "dhruv.com";
    strcat(web, domain);

    cout << "web: " << web << endl;
    cout << "strcmp(web, b): " << strcmp(b,web) << endl;  // return 1

    // Manual ASCII difference calculation
    int i = 0;
    while (web[i] != '\0' && b[i] != '\0') {
        if (web[i] != b[i]) {
            cout << "ASCII difference: " << (int)(web[i] - b[i]) << endl;
            break;
        }
        i++;
    }

    return 0;
}
