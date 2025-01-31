#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//hoare
int partition(int a[],int l, int r){
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while(true){
        // find the first a[i] that >= pivot
        do{
            ++i ;
        }
        while(a[i] < pivot);
        do{
            --j;
        }
        while(a[j] > pivot);
        if(i < j){
            swap(a[i], a[j]);
        }
        else{
            return j;
        }
    }
    return -1;
    
}
void qsort(int a[], int l, int r){
    if(l < r){
        int p = partition(a, l, r);
        qsort(a, l, p);
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
