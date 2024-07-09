#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> graph(N);
    for(int i = 0;i < M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int s,t;
    cin >> s >> t;
    s--;t--;
    vector<int> _min(N,INT_MAX);
    queue<pair<int,int>> q;
    _min[s] = 0;
    q.push({s,0});
    while(!q.empty()) {
        auto pair = q.front();
        q.pop();
        int cur = pair.first;
        int val = pair.second;
        if(val > _min[cur]) continue;
        for(auto t : graph[cur]) {
            int next = t.first;
            int cost = t.second;
            if(_min[next] > val+cost) {
                _min[next] = val+cost;
                q.push({next,val+cost});
            }
        }
    }
    cout << _min[t];
    return 0;
}