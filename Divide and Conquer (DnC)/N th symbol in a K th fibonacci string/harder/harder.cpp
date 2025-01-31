#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f[93];
string Find(ll n, ll k){
    if(n == 1){
        return "28tech";
    }
    if(n == 2){
        return "C++";
    }
    if(n == 3){
        if(k == 1)return"DSA";
        else return "JAVA";
    }
    if(k <= f[n - 3]){
        return Find(n - 3, k);
    }
    else if(k <= f[n - 2] +f[n - 3]){
        return Find(n - 2, k - f[n - 3]);
    }
    else {
        return Find(n - 1, k - f[n - 2] - f[n -3]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE                
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    int t; cin >> t;
    for(int i = 4; i <= 60; i ++){
        f[i] = f[i -1] + f[i - 2] + f[i - 3];
    }
    while(t --){
        ll n, k; cin >> n >> k;
        string s = Find(n, k) ; 
        cout << s << endl;
    }
    
    return 0;
}
