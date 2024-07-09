#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> adj(N);
    //for(int i = 0;i < N;i++) adj[i][i] = 0;
    for(int i = 0;i < M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int s,t;
    cin >> s >> t;
    s--;t--;
    vector<int> dist(N,INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //{cost,target}
    vector<bool> visited(N);
    for(auto pair : adj[s]) {
        pq.push({pair.second,pair.first});
    }
    int num_visit = 0;
    while(num_visit < N) {
        int next=s;
        while(visited[next] && !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            next = p.second;
        }
        //cout << "Cur is " << next << " with " << dist[next] << endl;
        visited[next] = true;
        num_visit++;
        for(auto pair : adj[next]) {
            int target = pair.first;
            int new_cost = dist[next] + pair.second;
            if(new_cost < dist[target]) {
                dist[target] = new_cost;
                pq.push({dist[target],target});
                //cout << "Update " << target << " to " << dist[target] << "\n";
            }
        }
    }

    cout << dist[t];
    

    return 0;
}