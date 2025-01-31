#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
int n, m;
int disc[1005], low[1005], parent[1005];
int timer = 0;
int ap[1005];

void Tarzan(int u, int par) {
	++timer;
	disc[u] = low[u] = timer;
	int child = 0;
	sort(adj[u].begin(), adj[u].end());
	for (int x : adj[u]) {
		if (x == par){
			continue;
		}
		if (!disc[x]) {
			Tarzan(x, u);
			if(par != -1 && disc[u] <= low[x]){
                ap[u] = 1;
            }
            else{
            	low[u] = min(low[u], low[x]);
        	}
		}
	}
	if (par == -1 && child > 1) {
        ap[u] = 1;
    }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i ++){
		if (!disc[i]) {
			Tarzan(i, -1);
		}
	}
	int res = 0;
    for( int i = 1; i <= n; i ++){
        res += ap[i];
    }
    cout << res << endl;
	return 0;
}