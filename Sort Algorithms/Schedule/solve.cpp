#include <bits/stdc++.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n; cin >> n;
    pair<int, int> a[n];
    int mins = INT_MAX;
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;
        pair<int, int> p{x, y};
        a[i] = p;
    } 
    sort(a, a + n);
    for(int i = n - 1; i >= 0; i --){
        int x = a[i].first, y = a[i].second;
        if(y < mins){
            cnt ++;
            mins = min(mins, x);
        }
    }
    cout << cnt;

    
    

    return 0;
}
