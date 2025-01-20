#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int>adj [1005];

bool visited[1000000];

void BFS(int u) {
    visited[u] = true;
    queue <int>Q;
    Q.push(u);
    while (!Q.empty()) {
        int v = Q.front();
        sort(adj[v].begin(), adj[v].end());
        Q.pop();
        for (int x: adj[v]) {
            if(!visited[x]){
                cout << v <<"->" << x << endl;
                visited[x] = true;
                Q.push(x);
            }
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
    
    BFS(u);
    return 0;
}

/*
SAMPLE INPUT:
25 77
12 22 1 5 8 27 12 14 11 19 11 16 5 4 7 10 77 56 44 33 12 88 76 72 100
SAMPLE OUTPUT:
1

*/