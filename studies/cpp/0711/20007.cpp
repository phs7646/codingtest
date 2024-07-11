#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int main() {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    vector<vector<pair<int,int>>> adj(N);
    for(int i = 0;i < M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    //daijk from Y to others
    vector<int> dist(N,INT_MAX);
    dist[Y] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<bool> visited(N);
    q.push({0,Y});
    int num_visit = 0;
    while(!q.empty()) {
        auto pair = q.top();
        int target = pair.second;
        q.pop();
        if(visited[target]) continue;
        visited[target] = true;
        num_visit++;
        if(num_visit >= N) break;
        for(auto pair2 : adj[target]) {
            if(visited[pair2.first]) continue;
            int new_cost = dist[target] + pair2.second;
            if(new_cost < dist[pair2.first]) {
                dist[pair2.first] = new_cost;
                q.push({new_cost,pair2.first});
            }
        }
    }
    vector<int> dists;
    for(int i = 0;i < N;i++) if(i != Y) dists.push_back(dist[i]);
    sort(dists.begin(),dists.end());
    int accum = 0;
    int count = 1;
    for(int n : dists) {
        if(n == INT_MAX || 2*n > X) {
            cout << -1;
            return 0;
        }
        if(accum + 2*n <= X) {
            accum += 2*n;
        } else {
            count++;
            accum = 2*n;
        }
    }
    cout << count;
    return 0;
}