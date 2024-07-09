#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<long long> visited;
long long answer = LLONG_MAX;

void dfs(int pos) {
    long long cur = visited[pos];
    for(auto pair : graph[pos]) {
        int next = pair.first;
        long long cost = static_cast<long long>(pair.second);
        if(visited[next] != 0) {
            //found cycle
            long long cyclevalue = cur+cost-visited[next];
            answer = min(answer,cyclevalue);
        } else {
            visited[next] = cur + cost;
            dfs(next);
            visited[next] = 0;
        }
    }
}

int main() {
    int V,E;
    cin >> V >> E;
    graph.resize(V);
    visited.resize(V,0);
    for(int i = 0;i < E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back({b,c});
    }
    visited[0] = 0;
    dfs(0);
    cout << answer;
    return 0;
}