#include <bits/stdc++.h>
using namespace std;

int n, row[100], col[100], xuoi[100], nguoc[100];
int res = 0;
void Try(int i){
    for(int j = 1; j <= n; j ++){
        if(col[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0){
            if(i == n){
                res ++;
            }
            col[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
            Try(i + 1);
            col[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
        }
    }
}
int main(){
    // #ifndef ONLINE_JUDGE                
    // freopen("input.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    // #endif
    cin >> n;
    Try(1);
    cout << res << endl;


    return 0;
}
