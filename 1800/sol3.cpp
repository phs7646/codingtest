#include <iostream>
#include <vector>
#include <queue>
#include <functional>


using namespace std;

int N,P,K;
vector<pair<int,int>> con[1000]; //con[i] = (p,c) => i랑 p는 c로 연결되어있다
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> costs; //minheap (cost,(a,b))
int D[1000];

void printD() {
    for(int i = 0;i < N;i++) {
        cout << D[i] << " ";
    }
    cout << "\n";
}
int main() {
    cin >> N >> P >> K;
    for(int i = 0;i < P;i++) {
        int x,y,c;
        cin >> x >> y >> c;
        x--;
        y--;
        con[x].push_back(make_pair(y,c));
        con[y].push_back(make_pair(x,c));
        costs.push(make_pair(c,make_pair(x,y)));
    }
    //init and calculate initial distance by BFS
    D[0] = 0;
    for(int i = 1;i < N;i++) D[i] = -1;
    bool checked[1000];
    for(int i = 0;i < N;i++) checked[i] = false;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int target = q.front();
        q.pop();
        for(pair<int,int> p : con[target]) {
            if(checked[p.first]) continue;
            D[p.first] = D[target] + 1;
            q.push(p.first);
            checked[p.first] = true;
        }
        checked[target] = true;
    }
    //check edgecase
    if(D[N-1] == -1) {
        cout << -1 << "\n";
        return 0;
    }
    if(D[N-1] <= K) {
        cout << 0 << "\n";
        return 0;
    }
    

    while(!q.empty())q.pop();
    while(!costs.empty()) {
        int x = costs.top().first; //let x is an answer
        while(costs.top().first == x) {
            pair<int,int> p = costs.top().second;
            costs.pop();
            int a = p.first;
            int b = p.second;
            if(D[a] < D[b]) {
                D[b] = D[a];
                q.push(b);
            } else if(D[a] > D[b]) {
                D[a] = D[b];
                q.push(a);
            }
        }
        while(!q.empty()) {
            int target = q.front();
            q.pop();
            for(pair<int,int> p2 : con[target]) {
                //target <-> p2
                int new_min = D[target] + (p2.second>x?1:0);
                if(D[p2.first] > new_min) {
                    D[p2.first] = new_min;
                    q.push(p2.first);
                }
            }
        }
        //cout << "for " << x <<"\n";
        //printD();
        if(D[N-1] <= K || costs.empty()) {
            cout << x << "\n";
            return 0;
        }
    }
}