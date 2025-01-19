#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve(ll a, ll b){
    while(a >= b){
        cout << "1/1";
        a -= b;
        if(a > 0){
            cout << " + ";
        }
    }
    while(a){
        ll x = b / a;
        if( b % a){
            x ++;
        }
        cout << "1/" << x ;
        a = a * x - b;
        b *= x;
        ll y = __gcd(a, b);
        a /= y;
        b /= y;
        if(a > 0){
            cout << " + ";
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a, b; cin >> a >> b;
    solve(a, b);
    

    
    
    return 0;
}
/*
SAMPLE INPUT:
65 228
SAMPLE OUT PT:
1/4 + 1/29 + 1/1653
*/