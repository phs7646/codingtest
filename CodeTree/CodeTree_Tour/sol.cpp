#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define maxNode 2000
#define maxInt 2100000000
#define debug 0


typedef struct {
    int id;
    int revenue;
    int dest;
    bool alive;
}item;
int N = 0;
vector<pair<int,int>> adj[maxNode]; //{cost,dest}
int dist[maxNode];
bool visited[maxNode];

map<int,int> idToIndex;
int listSize = 0;
item list[30000];
int getIndex(int id) {
    if(idToIndex.find(id) != idToIndex.end()) {
        return idToIndex[id];
    }
    return -1;
}
struct myCompare {
    bool operator() (pair<int,int> p1,pair<int,int> p2) {
        if(p1.first != p2.first) return p1.first < p2.first;
        else return list[p1.second].id > list[p2.second].id;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,myCompare> itempq;//{이익,index} maxheap

void daik(int start) {
    //initialize
    fill(visited,visited+maxNode,false);
    for(int i = 0;i < N;i++) dist[i] = maxInt;
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    int num_visit = 0;
    while(!pq.empty()) {
        pair<int,int> p = pq.top(); pq.pop();
        int cost = p.first;
        int target = p.second;
        if(visited[target] || dist[target] < cost) continue;
        visited[target] = true;
        num_visit++;
        if(num_visit == N) break;
        for(pair<int,int> next : adj[target]) {
            int newcost = cost + next.first;
            if(dist[next.second] > newcost) {
                dist[next.second] = newcost;
                pq.push({newcost,next.second});
            }
        }
    }
}
int main() {
    if(!debug) {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
    }
    int Q; cin >> Q;
    for(int q = 0; q < Q;q++) {
        int input; cin >> input;
        if(input == 100) {
            int M;
            cin >> N >> M;
            //for(int i = 0;i < N;i++) adj[i].clear();
            for(int m = 0;m < M;m++) {
                int v,u,w; cin >> v >> u >> w;
                adj[v].push_back({w,u});
                adj[u].push_back({w,v});
            }
            daik(0);
            if(debug) {
                cout << "After daik from 0\n";
                for(int i = 0;i < N;i++) cout << dist[i] << " ";
                cout << "\n";
            }
        } else if(input == 200) {
            int id,revenue,dest; cin >> id;
            idToIndex[id] = listSize++;
            list[idToIndex[id]].id = id;
            cin >> list[idToIndex[id]].revenue >> list[idToIndex[id]].dest;
            list[idToIndex[id]].alive = true;
            int adv = list[idToIndex[id]].revenue - dist[list[idToIndex[id]].dest];
            adv = adv < 0? -1 : adv;
            itempq.push({adv,idToIndex[id]});
            if(debug) cout << "Pushed " << adv << " " << idToIndex[id] << "\n";
        } else if(input == 300) {
            int id; cin >> id;
            int index = getIndex(id);
            if(index == -1) continue;
            list[index].alive = false;
        } else if(input == 400) {
            int sellIndex = -1;
            while(!itempq.empty()) {
                pair<int,int> p = itempq.top();
                int earn = p.first;
                int index = p.second;
                if(debug) cout << "checking " << earn << " " << index << endl;
                if(earn < 0) break;
                if(list[index].alive) {
                    //found!
                    sellIndex = index;
                    list[index].alive = false;
                    itempq.pop();
                    break;
                } else itempq.pop();
            }
            if(debug) cout << "sell (index : "<<sellIndex <<")";
            if(sellIndex == -1) cout << -1 << "\n";
            else cout << list[sellIndex].id << "\n";
        } else if(input == 500) {
            int s; cin >> s;
            //recalculate daik
            daik(s);
            //clear itempq
            itempq = priority_queue<pair<int,int>,vector<pair<int,int>>,myCompare>();
            //push itempq
            for(int idx = 0;idx < 30000;idx++) {
                if(!list[idx].alive) continue;
                int adv = list[idx].revenue - dist[list[idx].dest];
                adv = adv<0?-1 :adv;
                itempq.push({adv,idx});
            }
        }
    }
    return 0;
}