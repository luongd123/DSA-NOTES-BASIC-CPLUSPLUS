#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool Binary_search (int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            return true;
        }
        else if (x > a[mid]){
            l = mid + 1;
        }
        else if (x < a[mid]){
            r = mid - 1;
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    cout <<(int)Binary_search(a, n, x);
    return 0;
}

/*
SAMPLE INPUT:
25 77
1 4 5 5 7 8 10 11 11 12 12 12 14 16 19 22 27 33 44 56 72 76 77 88 100 
SAMPLE OUTPUT:
1

*/