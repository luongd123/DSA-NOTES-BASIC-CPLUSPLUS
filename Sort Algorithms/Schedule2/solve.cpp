#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout); 
    #endif 
    int n, m; cin >> n >> m;
    int a[n], b[m];
    multiset<int> se;
    for(int i= 0; i <n ; i ++){
        cin >> a[i];
        se.insert(a[i]);
    }
    for(int i= 0; i < m; i ++){
        cin >> b[i];
    }
    for(int i= 0; i < m; i ++){
        multiset<int>::iterator it = se.upper_bound(b[i]);
        
        if(b[i] < *se.begin() || se.empty() == true){
            cout << -1 << endl;
        }
        else{
            it--;
            cout << *it << endl;
                se.erase(it);
            
        }
    }


    return 0;
}
