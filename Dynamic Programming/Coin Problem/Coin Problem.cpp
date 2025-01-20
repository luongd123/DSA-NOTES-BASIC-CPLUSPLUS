#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;







int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, s; cin >> n >> s;
    int f[s + 1] = {0};
    f[0] = 0;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= s; i ++){
        f[i] = 1e9;
        for(int x : a){
            if(i >= x){
                f[i] = min(f[i], f[i - x] + 1);
            }
        }
    }
    if(f[s] == 1e9){
        cout << -1;
    }
    else{
        cout << f[s] << endl;
    }
    return 0;
}
// XYZ Bank currently has N bills of different denominations stored in array C[], 
// you should find a way to exchange the amount of money S so that the number of bills needed is the least. You can use a denomination an unlimited number of times.

/* 
SAMPLE INPUT:
10 37
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
SAMPLE INPUT:
4
*/
