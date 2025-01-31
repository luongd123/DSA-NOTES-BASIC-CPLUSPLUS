#include<bits/stdc++.h>
using namespace std; 
using ll = long long;



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int f[s + 1] = {0};
    f[0] = 1;
    for(int x : a){ 
        for(int i = s; i >= x; i --){
            if(f[i - x] == 1){
                f[i] = 1;
            }
        }

    }
    cout << f[s];
    
    
    
    return 0;
}
