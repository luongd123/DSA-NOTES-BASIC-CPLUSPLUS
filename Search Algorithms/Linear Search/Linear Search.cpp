#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool Linear_search(int a[], int n, int x){
    for(int i = 0; i < n; i ++){
        if(a[i] == x){
            return true;
        }
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x; cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    cout <<(int)Linear_search(a, n, x);
    return 0;
}

/*
SAMPLE INPUT:
25 77
12 22 1 5 8 27 12 14 11 19 11 16 5 4 7 10 77 56 44 33 12 88 76 72 100
SAMPLE OUTPUT:
1

*/