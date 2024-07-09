#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
int V,E,P;
vector<vector<pair<int,int>>> graph;


vector<int> daik(int start, int goal1, int goal2) {
    vector<bool> visited(V+1);
    vector<int> dist(V+1,INT_MAX);
    visited[0] = true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0,start});
    int num_visit = 0;
    while(num_visit < V) {
        //pick target
        int target = start;
        while(visited[target]) {
            target = pq.top().second;
            pq.pop();
        }
        //visit
        visited[target] = true;
        //if_end
        if(visited[goal1] && visited[goal2]) return dist;
        for(auto next : graph[target]) {
            int new_cost = dist[target] + next.second;
            if(dist[next.first] > new_cost) {
                dist[next.first] = new_cost;
                pq.push({new_cost,next.first});
            }
        }
        num_visit++;
        
    }
    return dist;
}

int main() {
    cin >> V >> E >> P;
    graph.resize(V+1);
    for(int i = 0;i < E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    //1부터 시작하는 다익스트라
    vector<int> distfrom1 = daik(1,P,V);
    //P부터 시작하는 다익스트라
    vector<int> distfromP = daik(P,V,0);
    if(distfrom1[P] + distfromP[V] == distfrom1[V]) {
        cout << "SAVE HIM";
    } else {
        cout << "GOOD BYE";
    }
    return 0;
}