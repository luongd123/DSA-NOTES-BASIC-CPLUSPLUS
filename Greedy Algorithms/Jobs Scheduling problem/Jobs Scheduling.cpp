#include<bits/stdc++.h>
using namespace std; 
using ll = long long;




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int n; cin >> n;
    pair<int, int> p[n];
    for(int i = 0; i < n ; i ++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, [](pair<int, int> p1, pair<int, int> p2)->bool{
        if(p1.second != p2.second){
            return p1.second < p2.second;
        }
        else{
            return p1.second - p1.first < p2.second - p2.first;
        }
    });
    int ans = 1;
    int end = p[0].second;
    for(int i = 1; i < n; i ++){
        if(p[i].first > end){
            end = p[i].second;
            ans ++;
        }
    }
    cout << ans <<"\n";

    
    
    return 0;
}




// Given N tasks with start and finish times, at each time you can only do 1 task. Find the maximum number of tasks you can do without overlapping time, 
// knowing that 2 tasks do not overlap time if the start time of the current task is greater than the finish time of the previous task.


/*
SAMPLE INPUT:
15
1 5
3 7
2 6
10 15
5 10
4 8
9 12
6 9
13 18
11 14
8 11
7 13
14 17
16 20
18 22
SAMPLE OUT PUT: 
4
*/