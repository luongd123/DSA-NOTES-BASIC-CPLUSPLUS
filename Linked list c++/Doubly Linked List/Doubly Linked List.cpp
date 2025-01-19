#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;











int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    Node *head = NULL;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            insertFront(head, x);
        }
        else if (t == 2) {
            int x; cin >> x;
            insertBack(head, x);
        }
        else if (t == 3) {
            int x, pos; cin >> x >> pos;
            insertMiddle(head, x, pos);
        }
        else if (t == 4) {
            deleteFront(head);
        }
        else if (t == 5) {
            deleteBack(head);
        }
        else if ( t == 6) {
            int pos; cin >> pos;
            deleteMiddle(head, pos);
        }
        else if (t == 7) {
            Display(head);
        }
    }
    
    
    return 0;
}

// TRY YOUR OWN INPUT : DDD

/* SAMPLE INPUT:
20
2 1
2 2 
2 3
2 4
1 5
1 6
1 7
1 8
1 9
1 123
3 12 4
3 22 6
3 209 8
4
5
5
6 1
6 6
7 
*/
/* 
SAMPLE OUTPUT:
123 9 8 7 6 5 1 2 3 4 
*/
