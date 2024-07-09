#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define INT_MAX 2147483647

using namespace std;

int D[1000];
bool visited[1000];
priority_queue<int,vector<int>,greater<int>> costs;
vector<pair<int,int>> con[1000];
int N,P,K;
void algo(int x) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
    //init
    D[0] = 0;
    visited[0] = true;
    for(int i = 1;i < N;i++) {
        D[i] = INT_MAX;
        visited[i] = false;
    }
    for(pair<int,int> p : con[0]) {
        if(p.second > x) D[p.first] = 1;
        else D[p.first] = 0;
        minheap.push(make_pair(D[p.first],p.first));
    }

    int unvisit = N-1;
    while(unvisit > 0) {
        pair<int,int> target = minheap.top();
        minheap.pop();
        if(visited[target.second]) continue;
        for(pair<int,int> p : con[target.second]) {
            if(visited[p.first]) continue;
            int cal = target.first + (p.second>x?1:0);
            if(cal < D[p.first]) {
                D[p.first] = cal;
                minheap.push(make_pair(cal,p.first));
            }
        }
        visited[target.second] = true;
        unvisit--;
    }
}

int main() {
    cin >> N >> P >> K;
    for(int i = 0;i < P;i++) {
        int x,y,cost;
        cin >> x >> y >> cost;
        x--;
        y--;
        costs.push(cost);
        con[x].push_back(make_pair(y,cost));
        con[y].push_back(make_pair(x,cost));
    }
    int x = 0;
    while(1) {
        //do algorithm
        algo(x);
        if(D[N-1] <= K) {
            cout << x << "\n";
            return 0;
        }
        if(D[N-1] == INT_MAX) {
            cout << -1 << "\n";
            return 0;
        }
        //next x
        int new_x = x;
        while(new_x == x) {
            if(costs.empty()) {
                cout << -1 << "\n";
                return 0;
            }
            new_x = costs.top();
            costs.pop();
        }
        x = new_x;
    }
}