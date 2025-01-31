#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<int, int> ii;

int n, m;

vector<ii> adj[1005];

bool visited[1000000];

void Prim(int u) {
    visited[u] = true;
    int d = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    for (ii x : adj[u]) {
        if(!visited[x.first]){
            Q.push({x.second, x.first});
        }
    }
    while (!Q.empty()) {
        ii top = Q.top(); Q.pop();
        int v = top.second, w = top.first;
        if (!visited[v]) {
            d += w;
            visited[v] = true;
            for (ii x : adj[v]) {
                if (!visited[x.first]) {
                    Q.push({x.second, x.first});
                }
            }
        }
    }
    cout << d << endl;
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    Prim(1);

    
    
    
    return 0;
}

