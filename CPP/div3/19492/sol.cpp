#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pp;
#define maxNode 100000
#define maxDepth 20

int N;
vector<int> energy;
int parents[maxNode][maxDepth];
vector<int> dist;
vector<vector<pp>> adj;

void dfs(int cur,int prev) {
    parents[cur][0] = prev;
    for(pp np : adj[cur]) {
        int next = np.first;
        if(next == prev) continue;
        //visit next
        int cost = np.second;
        dist[next] = dist[cur] + cost;
        dfs(next,cur);
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    dist.resize(N);
    energy.resize(N);
    for(int i = 0;i < N;i++) cin >> energy[i];
    for(int i = 0;i < N-1;i++) {
        int a,b,c; cin >> a >> b >> c;
        adj[a-1].emplace_back(b-1,c);
        adj[b-1].emplace_back(a-1,c);
    }
    //build dist and parents[i][0]
    dfs(0,0);

    //build remaining parents
    for(int pow = 1;pow < maxDepth;pow++) {
        for(int i = 1;i < N;i++) {
            parents[i][pow] = parents[parents[i][pow-1]][pow-1];
        }
    }
    cout << 1 << "\n";
    for(int i = 1;i < N;i++) {
        //i번방의 답 계산하기
        if(dist[i] <= energy[i]) {
            cout << 1 << "\n";
            continue;
        }
        //최대한 올라가기
        int step = maxDepth-1;
        int cur = i;
        int eng = energy[i];
        while(step >= 0 && cur > 0) {
            //step만큼 올라갈 수 있는가?
            int next = parents[cur][step];
            if(dist[cur] - dist[next] <= eng) {
                //갈 수 있음
                eng -= (dist[cur] - dist[next]);
                cur = next;
                
            } else {
                //갈 수 없음
                step--;
            }
        }
        cout << cur+1 << "\n";
    }

    return 0;
}