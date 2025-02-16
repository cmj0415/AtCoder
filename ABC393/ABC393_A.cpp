#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "sick") {
        if (s2 == "sick") {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        if (s2 == "sick") {
            cout << 3 << endl;
        } else {
            cout << 4 << endl;
        }
    }
}