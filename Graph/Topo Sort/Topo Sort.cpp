#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll mod = 1e9 + 7;
stack<int> st;
vector<int> adj[1005];
int visited[1005];
int cnt = 0;
int components[1005];
void Topo_sort(int u){
    visited[u] = 1;
    sort(adj[u].begin(), adj[u].end());
    for(int x : adj[u]){
        if(!visited[x]){
            Topo_sort(x);
        }
    }
    st.push(u);
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int n, m;cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i ++) {
        if (!visited[i]) {
            Topo_sort(i);
        }
    } 
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
