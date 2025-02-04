#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int n, a[100];
bool check ;
void init(){
    for(int i = 1; i <= n; i ++){
        a[i] = i;
    }
}
void Gen(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]){
        i --;
    }
    if(i == 0){
        check = false;
    }
    else{
        int j = n;
        while(a[j] < a[i]){
            j --;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
//next_permutation(a, a + n);
//prev_permutation(a, a + n);
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    check = true;
    init();
    while(check){
        for(int i = 1; i <= n; i ++)
            cout << a[i];
        cout << endl;
        Gen();
    }
    return 0;
} 
