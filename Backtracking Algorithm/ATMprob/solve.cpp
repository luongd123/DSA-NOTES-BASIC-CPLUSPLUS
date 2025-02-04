#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
ll n, s, a[31];
ll x[31];
ll res = 100000000000000000;
ll amax = LLONG_MIN;
bool check = false;
void nhap(){
    cin >> n >> s;
    for(ll i = 1; i <= n; i ++){
        cin >> a[i];
        amax = max(amax, a[i]);
    }
}
void Try(ll i, ll cnt, ll sum){
    for(ll j = 0; j <= 1; j ++){
        sum += a[i] * j;
        cnt += 1 * j;
        if(i == n){
            if(sum == s && cnt != 0){
                res = min(res, cnt);
                check = true;
            }
        }
        else if(sum + (res - cnt) * amax > s){
            Try(i + 1, cnt, sum);
        }
        sum -= a[i] * j;
        cnt -= 1 * j;
    }
}
int main(){
    #ifndef ONLINE_JUDGE                
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    nhap();
    Try(1, 0, 0);
    if(check){
        cout << res;
    }
    else{
        cout << -1;
    }
    return 0;
}
