#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

int sz[1005];
int parent[1005];
bool visited[1000000];

struct edge {
    int x, y, w;
};

vector<edge> E;

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

void Kruskal() {
    vector<edge> MST;
    int d = 0; // Sum of MTS
    sort(E.begin(), E.end(), [](edge x, edge y) -> bool{
        return x.w < y.w;
    });
    for (edge e : E) {
        if (Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    if(MST.size() < n - 1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << d << endl;
        for(edge e : MST){
            cout << e.x << ' ' << e.y << ' ' << e.w << endl;
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
    for (int i = 1; i <= m; i ++){
        int x, y, w; cin >> x >> y >> w;
        E.push_back({x, y, w});
    }
    Kruskal();

    
    
    
    return 0;
}

