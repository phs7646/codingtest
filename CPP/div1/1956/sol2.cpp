#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int main() {
    int V,E;
    cin >> V >> E;
    vector<vector<int>> adj(V,vector<int>(V,INT_MAX));
    for(int i = 0;i < V;i++) adj[i][i] = INT_MAX;
    for(int i = 0;i < E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a][b] = c;
    }

    for(int k = 0;k < V;k++) {
        for(int i = 0;i < V;i++) {
            for(int j = 0;j < V;j++) {
                //i->j 를 i->k->j로 업데이트
                if(adj[i][k] < INT_MAX && adj[k][j] < INT_MAX)
                    adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
            }
        }
    }
    int answer = INT_MAX;
    for(int i = 0;i < V;i++) answer = min(answer,adj[i][i]);
    if(answer == INT_MAX) cout << -1;
    else cout<<answer;

    return 0;
}