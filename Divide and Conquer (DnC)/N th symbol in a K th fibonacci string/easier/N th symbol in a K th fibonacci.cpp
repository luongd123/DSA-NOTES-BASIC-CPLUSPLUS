#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[93];
void khoitao(){
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 92; i ++){
        f[i] = f[i - 2] + f[i - 1];
    }
}

ll Find(ll n, ll k){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if( k <= f[n - 2]){
        return Find(n - 2, k);
    }
    else{
        return Find( n - 1, k - f[n -2]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    khoitao();
    ll n, k; cin >> n >> k;
    cout << Find(n, k);

    return 0;
}