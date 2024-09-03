#include<iostream>
#include<vector>
#include<queue>
#define MAXN 400
#define INF 1e9
using namespace std;
int N,P;
int capacity[MAXN<<1][MAXN<<1];
int flow[MAXN<<1][MAXN<<1];
int main() {
    cin >> N >> P;
    //2N개의 정점
    for(int i = 0;i < 2*N;i+=2) {
        //i를 in으로, i+1을 out으로 정점 배정
        capacity[i][i+1] = 1;    
    }
    for(int i = 0;i < P;i++) {
        int a,b; cin >> a >> b;
        a--;b--; //0base
        capacity[2*a+1][2*b] = INF;
        capacity[2*b+1][2*a] = INF;
    }
    //network flow
    int source = (0*2)+1;
    int sink = (1*2);
    int total = 0;

    while(true) {
        //find route
        vector<int> before(2*MAXN,-1);
        before[source] = source;
        queue<int> q; q.emplace(source);
        //bfs
        while(!q.empty()) {
            if(before[sink] != -1) break;
            int cur = q.front(); q.pop();
            for(int i = 0;i < 2*MAXN;i++) {
                if(before[i] == -1 && capacity[cur][i] - flow[cur][i] > 0) {
                    before[i] = cur;
                    q.emplace(i);
                }
            }
        } //bfs end
        if(before[sink] == -1) break;

        //calculate maximum flow amount of route
        int amount = INF;
        int cur = sink;
        while(cur != source) {
            amount = min(amount,capacity[before[cur]][cur] - flow[before[cur]][cur]);
            cur = before[cur];
        }

        //record flow
        cur = sink;
        while(cur != source) {
            flow[before[cur]][cur] += amount;
            flow[cur][before[cur]] -= amount;
            cur = before[cur];
        }

        total += amount;
    }
    cout << total;
    return 0;
}