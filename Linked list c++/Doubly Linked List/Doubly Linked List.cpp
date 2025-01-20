#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;

struct Node {
    int x;
    Node *next;
    Node *prev;
    Node(int x) {
        this->x = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

int size(Node *head) {
   int cnt = 0;
   while (head != NULL) {
      ++cnt;
      head = head->next;
   }
   return cnt;
}

void Display(Node *head) {
    while (head != NULL) {
        cout << head->x <<" ";
        head = head->next;
    }
}

Node *makeNode(int x) {
    return new Node(x);
}

void insertFront(Node *&head, int x) {
    Node *tmp = makeNode(x);
    if (head == NULL) {
        head = tmp;
    }
    else {
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
}

void insertBack(Node *&head, int x) {
    Node *tmp = makeNode(x);
    if (head == NULL) {
        head = tmp;
    }
    else {
        Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
        tmp->prev = p;
    }
}

void insertMiddle(Node *&head, int x, int pos) {
    int n = size(head);
    if (pos < 1 || pos > n + 1) { 
        return ;
    }
    else {
        if (pos == 1) {
            insertFront(head, x);
        }
        else{
            Node *p = head;
            Node *tmp = makeNode(x);
            for (int i = 1; i <= pos - 1;i ++){
                p = p->next;
            }
            tmp->next = p;
            p->prev->next = tmp;
            tmp->prev = p->prev;
            p->prev = tmp;
        }
    }
}

void deleteFront(Node *&head) {
    if (head == NULL) {
        return ;
    }
    Node *tmp = head;
    head = head->next;
    head->prev = NULL;
    delete tmp;
}

void deleteBack(Node *&head) {
    if (head == NULL) { 
        return;
    }
    if (head->next == NULL) { 
        delete head;
        head = NULL; 
        return;
    }
    Node *del = head;
    while (del->next != NULL) {
        del = del->next;
    }
    del->prev->next = NULL; 
    delete del; 
}

void deleteMiddle(Node *&head, int pos) {
    if (head == NULL) {
        return;
    }
    int n = size(head); 
    if (pos < 1 || pos > n) {
        return;
    }
    if (pos == 1) {
        deleteFront(head); 
        return;
    }
    Node *p = head;
    for (int i = 1; i < pos; i++) {
        p = p->next;
    }
    if (p->prev != NULL) {
        p->prev->next = p->next;
    }
    if (p->next != NULL) {
        p->next->prev = p->prev;
    }
    delete p;
}



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

/*
SAMPLE INPUT:
20
1 1 -> 1
1 2 -> 2 1
1 100 -> 100 2 1
1 200 -> 200 100 2 1
3 90 2 -> 200 90 100 2 1
4 -> 90 100 2 1
1 3 -> 3 90 100 2 1
1 4 -> 4 3 90 100 2 1
2 5 -> 4 3 90 100 2 1 5
2 6 -> 4 3 90 100 2 1 5 6
2 7 -> 4 3 90 100 2 1 5 6 7
3 8 3 -> 4 3 8 90 100 2 1 5 6 7
3 9 6 -> 4 3 8 90 100 9 2 1 5 6 7
4 -> 3 8 90 100 9 2 1 5 6 7
4 -> 8 90 100 9 2 1 5 6 7
5 -> 8 90 100 9 2 1 5 6 
5 -> 8 90 100 9 2 1 5 
6 2 -> 8 100 9 2 1 5
6 1 -> 100 9 2 1 5
7

SAMPLE OUTPUT:
100 9 2 1 5 
*/
