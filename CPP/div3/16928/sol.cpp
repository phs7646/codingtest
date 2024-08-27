#include<iostream>
#include<queue>
#define SIZE 100
using namespace std;
int memo[SIZE+1];
int portal[SIZE+1];
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    
    for(int i = 0;i < N;i++) {
        int a,b; cin >> a >> b;
        portal[a] = b;
    }
    for(int i = 0;i < M;i++) {
        int a,b; cin >> a >> b;
        portal[a] = b;
    }
    
    queue<int> q;
    q.emplace(1);
    while(true) {
        int cur = q.front(); q.pop();
        for(int next = cur+1, end = min(cur+6,SIZE); next <= end;next++) {
            int cell = portal[next] == 0 ? next : portal[next];
            if(memo[cell] == 0) {
                memo[cell] = memo[cur] + 1;
                if(cell == SIZE) {
                    cout << memo[cell];
                    return 0;
                }
                q.emplace(cell);
            }
        }
    }


    return 0; 
}