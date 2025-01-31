#include<bits/stdc++.h>
using namespace std; 
using ll = long long;

int n, m, k;
vector<int> adj[1005];
int color[1005];
int visited[1005];

void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(color, -1, sizeof(color));
}
bool BFS(int u){
    color[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : adj[v]){
            if(color[x] == -1){
                color[x] = 1 - color[v];
                q.push(x);
            }
            if(color[x] == color[v]){
                return false;
            }
        }
    }
    return true;
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);  
    nhap();
    bool check = true;
    for(int i = 1; i <= n; i ++){
        if(color[i] == -1){
            if(!BFS(i)){
                check = false;
            }
        }
    }
    if(check){
        cout <<"YES\n";
    }
    else{
        cout <<"NO\n";
    }

    
    
    return 0;
}
