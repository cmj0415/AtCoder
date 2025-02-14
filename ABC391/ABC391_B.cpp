#include <iostream>
#include <vector>
using namespace std;

bool check(int a, int b, int n, int m, vector<vector<char>> &S, vector<vector<char>> &T) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (S[a + i][b + j] != T[i][j]) return 0;
        }
    }
    return 1;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> S(n, vector<char>(n));
    vector<vector<char>> T(m, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> T[i][j];
        }
    }
    for (int a = 0; a <= n - m; a++) {
        for (int b = 0; b <= n - m; b++) {
            if (check(a, b, n, m, S, T)) {
                cout << a + 1 << " " << b + 1 << endl;
                return 0;
            }
        }
    }
}