#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int a[100], n;
bool check;

void Gen(){
    int i = n;
    while (i >= 1 && a[i] == 1){
        a[i] = 0;
        i --;
    }
    if(i == 0){
        check = false;
    }
    else{
        a[i] = 1;
    }
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    check = true;
    while(check){
        for(int i = 1; i <= n; i ++){
            cout << a[i];
        }
        cout << endl;
        Gen();
    }
    return 0;
} 
