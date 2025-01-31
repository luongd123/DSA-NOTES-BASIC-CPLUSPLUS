#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;


ll f[1005][1005];



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int v, n; cin >> n >> v;
    ll w[n], c[n];
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i ++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i ++){ // do vat thu i
        for(int j = 1; j <= v; j ++){// trong luong toi da la j
            f[i][j] = f[i - 1][j];
            if(j >= w[i]){
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + c[i]);
            }
        }
    }
    cout << f[n][v];

    return 0;
}
