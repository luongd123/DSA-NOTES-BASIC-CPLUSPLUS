#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;
int f[1005][1005];






int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    string s; cin >> s;
    s = " " + s;
    int res = -1;
    int n = s.size();
    for(int i = 1; i <= s.size(); i ++ ){
        f[i][i] = 1;
    }
    for(int len = 2; len <= n; len ++){
        for(int i = 1; i <= n - len + 1; i ++){
            int j = i + len - 1;
            if(len == 2){
                f[i][j] = (int)(s[i] == s[j]);
            }
            else{
                f[i][j] = (int)(f[i + 1][j - 1] && s[i] == s[j]);
            }
            if(f[i][j] == 1){
                res = max(res, len);
            }
        }
    }
    cout << res;
    

    
    
    
    return 0;
}
