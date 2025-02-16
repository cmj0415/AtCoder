#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int d = 1; i + 2 * d < len; d++) {
            if (s[i] == 'A' && s[i + d] == 'B' && s[i + 2 * d] == 'C') {
                count++;
            }
        }
    }
    cout << count << endl;
}