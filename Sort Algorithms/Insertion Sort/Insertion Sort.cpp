#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void insertion_sort(int a[], int n){
    for(int i = 0; i < n ; i ++){
        int pos = i - 1;
        int x = a[i];
        while(pos >= 0 && x < a[pos]){
            a[pos + 1] = a[pos];
            -- pos;
        }
        a[pos + 1] =x;
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    insertion_sort(a, n);
    for(int i = 0; i < n; i ++){
        cout << a[i] <<" ";
    }
    return 0;
}

/*
SAMPLE INPUT:
25
12 22 1 5 8 27 12 14 11 19 11 16 5 4 7 10 77 56 44 33 12 88 76 72 100
SAMPLE OUTPUT:
1 4 5 5 7 8 10 11 11 12 12 12 14 16 19 22 27 33 44 56 72 76 77 88 100 

*/