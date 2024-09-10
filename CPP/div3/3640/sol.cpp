#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define INF 1e9
#define MAXV 2001
using namespace std;
typedef pair<int,int> pp;

int v,e,numV;
int flow[MAXV][MAXV];
int capa[MAXV][MAXV];
int cost[MAXV][MAXV];
vector<int> graph[MAXV];
int mfmc() {
    int ret = 0;
    int source = 0; //0_in
    int sink = 2*(v-1)+1; //v-1_out
    
    while(true) {
        //find route
        vector<int> before(MAXV,-1);
        before[source] = source;
        queue<int> q; q.emplace(source);
        while(!q.empty()) {
            if(before[sink] != -1) break; //found
            int cur = q.front(); q.pop();
            for(int next : graph[cur]) {
                if(before[next] == -1 && capa[cur][next] - flow[cur][next] > 0) {
                    before[next] = cur;
                    q.emplace(next);
                }
            }
        } //bfs end
        if(before[sink] == -1) break; //no route

        int amount = INF;
        //calculate maximum flow and cost
        for(int p = sink; p != source; p = before[p]) {
            amount = min(amount,capa[before[p]][p] - flow[before[p]][p]);
            ret += cost[before[p]][p];
        }
    }
    return ret;
}

int main() {
    //cin.tie(nullptr);
    while(cin >> v) {
        cin >> e;
        //num vertice : in+out = 2V
        int numV = v>>1;

        //initialize
        for(int i = 0;i < numV;i++) graph[i].clear();
        fill(&flow[0][0],&flow[MAXV-1][MAXV],0);
        fill(&capa[0][0],&capa[MAXV-1][MAXV],0);
        fill(&cost[0][0],&cost[MAXV-1][MAXV],0);

        //start, end vertice : capacity 2
        capa[0][1] = 2;
        capa[2*(v-1)][2*(v-1)+1] = 2;
        for(int i = 1;i < v-1;i++) capa[2*i][2*i+1] = 1;

        for(int i = 0;i < e;i++) {
            //input
            int a,b,c; cin >> a >> b >> c;
            a--;b--; //0base
            graph[a].push_back(b);
            graph[b].push_back(a);
            capa[2*a+1][2*b] = 1; //aout -> b_in
            cost[2*a+1][2*b] = c;
            cost[2*b][2*a+1] = -c;
        }

        cout << mfmc() << "\n";
    }

    return 0;
}