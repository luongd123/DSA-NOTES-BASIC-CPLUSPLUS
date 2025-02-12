#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int maxn = 200005;
ll n, a[maxn], t[4 * maxn];

// xay cay
void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    }
    else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
        t[v] = val;
    }
    else {
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, val);
        }
        else {
            update(2 * v + 1, mid + 1, r, pos val);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return t[v];
    }
    int tmid = (tl + tr) / 2;
    int s1 = query(2 * v, tl, tmid, l, min(r, tmid));
    int s2 = query(2 * v + 1, tm + 1, tr, max(l, tmid), r);
    return s1 + s2;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    build(1, 0, n - 1);
    int q; cin >> q;
    while (q --) {
        
    } 
    
    return 0;
}

