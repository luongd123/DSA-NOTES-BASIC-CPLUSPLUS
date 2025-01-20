#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
struct matrix{
    ll a[2][2];
    friend matrix operator * (matrix x, matrix y){
        matrix kq;
        for(int i= 0; i < 2; i ++){
            for(int j = 0; j < 2; j ++){
                kq.a[i][j] = 0;
                for(int k = 0; k < 2; k ++){
                    kq.a[i][j] += x.a[i][k]*y.a[k][j];
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq;
    }
};
matrix pMod(matrix a, ll n){
    if(n == 1){
        return a;
    }
    matrix x = pMod(a, n /2);
    if(n % 2 == 0){
        return x * x;
    }
    else{
        return x * x * a;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    matrix x;
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 2; j ++){
            x.a[i][j] = 1; 
        }
    }
    x.a[1][1] = 0;
    ll n; cin >> n;
    matrix kq = pMod(x, n);
    cout << kq.a[1][0];

    return 0;
}

/*
SAMPLE INPUT :
200
SAMPLE OUTPUT :
349361645
*/
