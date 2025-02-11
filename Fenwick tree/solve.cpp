#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int n, q, a[200000], BIT[200000];


// Xay cay
void update(int pos, int val) {
    for (; pos <= n; pos += pos & (-pos)) {
        cout << pos <<" ";
        BIT[pos] += val;
    }
}


// truy van: Tinh tong tu vi tri 1 den vi tri n
int query(int pos) {
    int sum = 0; 
    for (; pos >= 1; pos -= pos & (-pos)) {
        sum += BIT[pos];
    }
    return sum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        update(i, a[i]);
    }

    while (q --) {
        int c, x, y; cin >> c >> x >> y;
        if (c == 1) {
            update(x, y);
        }
        else if (c == 2) {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    
    return 0;
}

