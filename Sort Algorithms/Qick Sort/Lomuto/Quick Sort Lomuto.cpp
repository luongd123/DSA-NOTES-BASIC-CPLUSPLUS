#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//lomuto
int partition(int a[],int l, int r){
    int pivot = a[r];
    int i = l - 1;  
    for(int j = l; j < r; j ++){
        if(a[j] <= pivot){
            i ++;
            swap(a[i], a[j]);
        }
    }
    i ++;
    swap(a[i], a[r]);
    return i;
}
void qsort(int a[], int l, int r){
    if(l <= r){
        int p = partition(a, l, r);
        qsort(a, l, p - 1);
        qsort(a, p + 1, r);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    qsort(a, 0, n - 1);
    for(int x : a){
        cout << x << " ";
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