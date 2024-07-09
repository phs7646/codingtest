#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define INT_MAX 2147483647

using namespace std;

int D[1000];
bool visited[1000];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> costs; // (cost, v1, v2)
vector<pair<int,int>> con[1000]; //pair(p,cost)
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap; //pair(cost,p)
int N,P,K;
void algo() {
    //init
    D[0] = 0;
    visited[0] = true;
    for(int i = 1;i < N;i++) {
        D[i] = INT_MAX;
        visited[i] = false;
    }
    for(pair<int,int> p : con[0]) {
        D[p.first] = 1;
        minheap.push(make_pair(D[p.first],p.first));
    }

    int unvisit = N-1;
    while(unvisit > 0) {
        pair<int,int> target = minheap.top();
        minheap.pop();
        if(visited[target.second]) continue;
        for(pair<int,int> p : con[target.second]) {
            if(visited[p.first]) continue;
            int cal = target.first + 1;
            if(cal < D[p.first]) {
                D[p.first] = cal;
                minheap.push(make_pair(cal,p.first));
            }
        }
        visited[target.second] = true;
        unvisit--;
    }
}

void update(int x) {
    while(!minheap.empty()) {
        pair<int,int> p = minheap.top();
        minheap.pop();
        if(D[p.second] > p.first) continue;
        for(pair<int,int> p2 : con[p.second]) { //p,cost
            int target = p2.first;
            int cost = p2.second > x ? 1 : 0;
            if(D[target] > p.first + cost) {
                D[target] = p.first + cost;
                minheap.push(make_pair(D[target],target));
            }
        }
    }
}

int main() {
    cin >> N >> P >> K;
    for(int i = 0;i < P;i++) {
        int x,y,cost;
        cin >> x >> y >> cost;
        x--;
        y--;
        costs.push(make_pair(cost,make_pair(x,y)));
        con[x].push_back(make_pair(y,cost));
        con[y].push_back(make_pair(x,cost));
    }
    algo(); //perform daik for all edge is 1
    if(D[N-1] <= K) {
        cout << 0 << "\n";
        return 0;
    }
    if(D[N-1] == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }
    while(true) {
        //select new x
        int x = costs.top().first;
        while(!minheap.empty()) minheap.pop();
        while(costs.top().first == x) {
            pair<int,pair<int,int>> p = costs.top();
            costs.pop();
            int a = p.second.first;
            int b = p.second.second;
            if(D[a] > D[b]) {
                D[a] = D[b];
                minheap.push(make_pair(D[a],a));
            } else if (D[a] < D[b]) {
                D[b] = D[a];
                minheap.push(make_pair(D[b],b));
            }
        }
        //update D[]
        update(x);
        if(D[N-1] <= K) {
            cout << x << "\n";
            return 0;
        }
    }
    
}