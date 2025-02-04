#include <bits/stdc++.h>

using namespace std;

using ll = long long ;

int n, k, a[100];
bool final = false;


void sinh()
{
    int i = k;
    while(i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if(i == 0)
    {
        final = false;
    }
    else 
    {
        a[i] ++;
        for ( int j = i + 1 ; j <= k; j ++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
    
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    final = true;
    while(final)
    {
        for ( int i = 1; i <= k; i ++)
        {
            cout << a[i];
            
        }
        cout << "\n";
        sinh();
    }
    return 0;
}