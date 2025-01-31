#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

vector<int> adj[1005];
int visited[1000];
int color[1005];

bool dfs(int u){
    color[u] = 1;
    visited[u] = 1;
    for(int x : adj[u]){
        if(color[x] == 1){
            return true;
        }
        if(!color[x]){
            if(dfs(x)) return true;
        }
    }
    color[u] = 2;
    return false;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);  
    int n, m;
    cin >> n >> m ;
    vector<pair<int, int>> cc;
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i ++){
        if(dfs(i)){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
