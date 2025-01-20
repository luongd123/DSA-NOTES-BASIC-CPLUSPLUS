#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int>adj [1005];

bool visited[1000000];

void DFS(int u) {
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for (int x: adj[u]) {
        if (visited[x] == false) {
            cout << u <<"->" <<x << endl;
            DFS(x);
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, u; cin >> n >> m >> u;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    DFS(u);
    return 0;
}

