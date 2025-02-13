#include <iostream>
#include <vector>
using namespace std;
typedef struct {
    int op;
    pair<int, int> pr;
} Edge;
int find(int x, vector<int> &parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}
int Union(int x, int y, vector<int> &parent) {
    int r1 = find(x, parent);
    int r2 = find(y, parent);
    if (r1 == r2) {
        return 1;
    } else {
        parent[r2] = r1;
        return 0;
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    // parent array for DSU
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    // construct graph and find loops
    vector<Edge> vec; // records the edges that cause loops
    vector<bool> exist(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        exist[u] = exist[v] = 1;
        if (Union(u, v, parent)) {
            vec.push_back({i + 1, {u, v}});
        }
    }

    // count the number of connected components (which is the number of roots)
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    
    printf("%d\n", count - 1);

    // first pass: connecting lone vertices
    int index = 0;
    for (int i = 1; i <= n; i++) {
        if (exist[i]) continue;
        Union(vec[index].pr.first, i, parent);
        printf("%d %d %d\n", vec[index].op, vec[index].pr.first, i);
        index++;
    }

    // second pass: connecting each components with vertex 1
    for (int i = 2; i <= n; i++) {
        if (find(i, parent) == find(1, parent)) {
            continue;
        } 
        if (find(vec[index].pr.first, parent) == find(1, parent)) {
            Union(vec[index].pr.first, i, parent);
            printf("%d %d %d\n", vec[index].op, vec[index].pr.first, i);
        } else {
            Union(1, vec[index].pr.first, parent);
            printf("%d %d %d\n", vec[index].op, vec[index].pr.first, 1);
        }
        index++;
    }
}