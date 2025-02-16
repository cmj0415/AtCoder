#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> edge[n];
    int count = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            count++;
            continue;
        }
        if (u > v) swap(u, v);
        if (!edge[u].insert(v).second) {
            count++;
        }
    }
    cout << count << endl;
}