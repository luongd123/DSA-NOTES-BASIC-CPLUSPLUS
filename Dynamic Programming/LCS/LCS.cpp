#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;
int a[1005][1005];

void LCS(string s1, string s2){
    int n = s1.size(), m = s2.size();
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1;j <= m; j ++){
            if(s1[i - 1] == s2[j - 1]){
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else{
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    string s1, s2;
    cin >> s1 >> s2;
    LCS(s1, s2);
    cout << a[s1.size()][s2.size()];
    
    

    
    
    
    return 0;
}
