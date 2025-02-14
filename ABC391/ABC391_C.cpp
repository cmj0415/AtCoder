#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nest(n + 1, 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) pos[i] = i;
    int multipigeon = 0;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, h;
            cin >> p >> h;
            nest[pos[p]]--;
            if (nest[pos[p]] == 1) multipigeon--;
            nest[h]++;
            if (nest[h] == 2) multipigeon++;
            pos[p] = h;
        } else {
            cout << multipigeon << endl;
        }
    }
}