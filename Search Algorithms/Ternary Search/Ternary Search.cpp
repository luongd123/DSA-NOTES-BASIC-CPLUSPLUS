#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool Ternary_search(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (a[mid1] == x) {
            return true;
        }
        if (a[mid2] == x) {
            return true;
        }

        if (x < a[mid1]) {
            r = mid1 - 1; 
        } else if (x > a[mid2]) {
            l = mid2 + 1; 
        } else {
            l = mid1 + 1; 
            r = mid2 - 1;
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
    cout <<(int)Ternary_search(a, n, x);
    return 0;
}

/*
SAMPLE INPUT:
25 77
1 4 5 5 7 8 10 11 11 12 12 12 14 16 19 22 27 33 44 56 72 76 77 88 100 
SAMPLE OUTPUT:
1

*/