#include <iostream>
#include <vector>
#define ff first
#define ss second
using namespace std;
int find(int x, vector<int> &parent) {
    return x == parent[x] ? x : find(parent[x], parent);
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
    vector<int> adj[n + 1];

    // DSU
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    // construct graph and find loops
    vector<pair<int, int>> vec; // records the edges that cause loops
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (Union(u, v, parent)) {
            printf("Loop occurs when connecting %d %d\n", u, v);
            vec.push_back({u, v});
        }
    }
    // calculate the number of connected components
    int components = 0;
    vector<bool> vis(m + 1, 0);
    vector<int> queue(m);
    vector<int> code(n + 1); // records which component each vertex is in
    vector<int> representative(n + 1); // records a representative vertex of a component
    // bfs
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int top = 0, rear = 0;
        representative[idx] = i;
        queue[rear++] = i;
        vis[i] = true;
        while(top < rear){
            int pos = queue[top++];
            code[pos] = idx; // vertex 'pos' is in the idx-th component
            for (auto j : adj[pos]) {
                if (vis[j]) continue;
                queue[rear++] = j;
                vis[j] = true;
            }
        }
        components++;
        idx++;
    }
    for (int i : representative) printf("%d ", i);
    printf("\n");
    printf("%d\n", components - 1);
    if (components == 1) return 0;

    // record codes of components with no loop containing
    vector<bool> hasLoop(components + 1, 0);
    for (auto p : vec) {
        hasLoop[code[p.first]] = 1;
        hasLoop[code[p.second]] = 1;
    }
    vector<int> noLoopComponents;
    for (int i : hasLoop) {
        if (!hasLoop[i]) noLoopComponents.push_back(i);
    }

    // reconnect redundant edges to another component
    int index = 0, size = vec.size();
    for (auto p : vec) {
        printf("%d %d %d", p.first, p.second, representative[noLoopComponents[index]]);
        if (index < vec.size() - 1) index++;
    }
}