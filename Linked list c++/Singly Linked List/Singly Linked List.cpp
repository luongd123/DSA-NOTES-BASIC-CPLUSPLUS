#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;

struct Node {
    Node *next;
    int x;
    Node(int x) {
        this->x = x;
        this->next = NULL;
    }
};

Node *makeNode(int x){
    return new Node(x);
}

int size(Node *head) {
   int cnt = 0;
   while (head != NULL) {
      ++cnt;
      head = head->next;
   }
   return cnt;
}

void Display(Node *head){
    while(head != NULL){
        cout << head->x <<" ";
        head = head->next;
    }
}


void insertFront(Node *&head, int x){
    Node *tmp = makeNode(x);
    if (head == NULL) {
        head = tmp;
    }
    else {
        tmp->next = head;
        head = tmp;
    }
}

void insertBack(Node *&head, int x) {
    Node *tmp = makeNode(x);
    if (head == NULL) {
        head = tmp;
    }
    else{
        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

void insertMiddle(Node *&head, int x, int pos){
    int n = size(head);
    if (pos < 1 || pos > n + 1) {
        return ;
    }
    else {
        if (pos == 1) {
            insertFront(head, x);
        }
        else {
            Node *p = head;
            for (int i = 1; i <= pos - 2; i ++){ 
                p = p->next;
            }
            Node *tmp = makeNode(x);
            tmp->next = p->next;
            p->next = tmp;
        }
    }
}

void deleteFront(Node *&head){
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteBack(Node *&head) {
    if (head == NULL) return;
    Node *temp = head;
    if (temp->next == NULL) {
        head = NULL; delete temp;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *last = temp->next; 
    temp->next = NULL;
    delete last;
}


void deleteMiddle(Node *&head, int pos) {
    int n = size(head);
    if(pos < 1 || pos > n) return; // ko xoa
    if(pos == 1) deleteFront(head);
    else {
        Node *temp = head;
        for (int i = 1; i <= pos - 2; i++) {
            temp = temp->next;
        }
        //temp : k - 1
        Node *kth = temp->next; 
        
        temp->next = kth->next;
        delete kth; // free(kth)
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    Node *a = NULL;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            insertFront(a, x);
        }
        else if (t == 2) {
            int x; cin >> x;
            insertBack(a, x);
        }
        else if (t == 3) {
            int x, pos; cin >> x >> pos;
            insertMiddle(a, x, pos);
        }
        else if (t == 4) {
            deleteFront(a);
        }
        else if (t == 5) {
            deleteBack(a);
        }
        else if (t == 6) {
            int pos; cin >> pos;
            deleteMiddle(a, pos);
        }
        else if (t == 7) {
            Display(a);
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


