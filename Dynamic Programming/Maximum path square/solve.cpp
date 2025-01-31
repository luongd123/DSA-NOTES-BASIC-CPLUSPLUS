#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;


int a[1005][1005];
ll f[1005][1005];

void solve(){
    ll res = -1;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] == 1){
                f[i][j] = min({f[i- 1][j], f[i][j - 1], f[i -1 ][j - 1]}) + 1;
            

        }
        res = max(res, f[i][j]);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j ++){
    //         cout << f[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    cout << res;
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    
    

    
    
    
    return 0;
}
