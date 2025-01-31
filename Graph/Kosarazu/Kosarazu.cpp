#include <bits/stdc++.h>
//halo
using namespace std;
using ll = long long ;
const ll mod = 1e9 + 7;
stack<int> st;
vector<int> adj[1005];
vector<int> re_adj[1005];
int visited[1005];


void DFS(int u) {
    visited[u] = 1;
    sort(re_adj[u].begin(), re_adj[u].end());
    for (int x: re_adj[u]) {
        if (visited[x] == 0) {
            DFS(x);
        }
    }
}


void Topo_sort(int u) {
    visited[u] = 1;
    sort(adj[u].begin(), adj[u].end());
    for (int x : adj[u]) {
        if (!visited[x]) {
            Topo_sort(x);
        }
    }
    st.push(u);
}


void Kosarazu() {
    int components = 0; //
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            DFS(u);
            ++components;
        }
    }
    cout << components << endl;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int n, m;cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        re_adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i ++){
        if(!visited[i]){
            Topo_sort(i);
        }
    }
    memset(visited, 0, sizeof(visited));  
    Kosarazu();

    return 0;
}
