#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void Merge(int a[], int l, int mid, int r){
    vector<int> left(a + l, a + mid + 1);
    vector<int> right(a + mid + 1, a + r + 1);
    int i = 0, j = 0, index = l ;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            a[index] = left[i];
            index ++; i ++;
            
        }
        else{
            a[index] = right[j];
            index ++; j ++;
            
        }
    }
    while(i < left.size()){
            a[index] = left[i];
            index ++; i ++;
            
        }
        while(j < right.size()){
            a[index] = right[j];
            index ++; j ++;
            
        }
}
 void Mergesort(int a[], int l, int r){
    if(l < r){
        int mid = (r  + l) / 2;
        Mergesort(a, l, mid );
        Mergesort(a, mid + 1, r);
        Merge(a, l, mid, r);
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
    Mergesort(a, 0, n - 1);
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