#include <bits/stdc++.h>

using namespace std;

using ll = long long ;
int a[10000000], n, k, fin = 0;
 
void init()
{
    for ( int i = 1; i <= k; i ++)
    {
        a[i] = 1;
    }
}
void Gen()
{
    int i = k;
    while( i >= 1 && a[i] == n)
    {
        --i;
    }
    if( i == 0 )
    {
        fin = 1;
    }
    else 
    {
        a[i]++;
        for( int j = i + 1; j <= k; j++)
        {
            a[j] = 1;
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
    int b[1000];
    
    init();
    while(fin == 0)
    {
        for ( int i = 1; i <= k ; i ++)
        {
            cout << a[i];
        }
        cout << endl;
        Gen();
        
    }
    return 0;
}