#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int n; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    int f[n];
    for(int i = 0; i < n; i ++){
        f[i] = 1;
        for(int j = 0; j < i; j ++){
            if(a[i] > a[j]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    cout << *max_element(f, f + n);

    return 0;
}
