#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> adj[1001];
int assign[1001];
vector<bool> visited;

bool tryMatch(int x) {
    for(int i = 0;i < adj[x].size();i++) {
        int job = adj[x][i];
        if(visited[job]) continue;
        visited[job] = true;
        if(assign[job] == 0 || tryMatch(assign[job])) {
            //해당 job에 연결 가능 하거나, 혹은 다른 job으로 변경하거나
            assign[job] = x;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for(int i = 1;i <= N;i++) {
        int K; cin >> K;
        for(int k = 0;k < K;k++) {
            int w; cin >> w;
            adj[i].emplace_back(w);
        }
    }

    int answer = 0;
    for(int i = 1; i <= N;i++) {
        visited = vector<bool>(N+1);
        if(tryMatch(i)) answer++;
    }
    cout << answer;
    
    return 0;
}