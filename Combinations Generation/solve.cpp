#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, a[100];
bool final = true;

// Khởi tạo tổ hợp đầu tiên {1, 2, ..., k}
void init() {
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

// Sinh tổ hợp kế tiếp
void sinh() {
    int i = k;
    while (i >= 1 && a[i] == n - k + i) {
        i--;
    }
    if (i == 0) {
        final = false;  // Khi không thể sinh tiếp tổ hợp, kết thúc vòng lặp
    } else {
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cin >> n >> k;

    init();  // Khởi tạo tổ hợp đầu tiên

    while (final) {
        for (int i = 1; i <= k; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        sinh();
    }

    return 0;
}