#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V,E;
    cin >> V >> E;
    vector<vector<pair<int,int>>> graph(V+1); // {cost, opponent}
    for(int i = 0;i < E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> selected(V+1);
    selected[1] = true;
    int count = 1;
    int answer = 0;
    //select 1
    for(auto pair : graph[1]) pq.push(pair);

    while(count < V) {
        auto pair = pq.top();
        pq.pop();
        if(selected[pair.second]) continue;
        //pair.second를 트리에 추가
        //cout << pair.second << "를 " << pair.first << "를 내고 추가!\n";
        selected[pair.second] = true;
        answer += pair.first;
        for(auto pair : graph[pair.second]) {
            if(selected[pair.second] == false) pq.push(pair);
        }
        count++;
    }
    cout << answer;
    return 0;
}