#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int>adj [1005];

int n, m;


int sz[1005];
int parent[1005];
bool visited[1000000];

void init() {
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (u == parent[u]) {
        return u;
    }
    else {
        return parent[u] = find(parent[u]);
    }
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return false;
    }
    else {
        if (sz[u] > sz[v]) {
            parent[v] = u;
            sz[u] += sz[v];
        }
        else {
            parent[u] = v;
            sz[v] += sz[u];
        }
    } 
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n >> m;
    init();
    int components = n;
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        if(Union(x, y)){
            components --;
        }
    }
    cout << components << endl;
    
    
    return 0;
}

