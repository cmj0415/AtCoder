#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'N') cout << 'S';
        else if (s[i] == 'S') cout << 'N';
        else if (s[i] == 'E') cout << 'W';
        else if (s[i] == 'W') cout << 'E';
    }
}