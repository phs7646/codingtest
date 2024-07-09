#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int N,M,K;

vector<int> dijk(int target, const vector<vector<pair<int,int>>>& graph) {
    vector<int> dist(N,INT_MAX);
    dist[target] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,target));

    while(!pq.empty()) {
        int cdist = pq.top().first;
        int ccity = pq.top().second;
        pq.pop();
        if(dist[ccity] < cdist) continue;

        for(auto& edge : graph[ccity]) {
            int ncity = edge.first;
            int ndist = edge.second;
            if(cdist + ndist < dist[ncity]) {
                dist[ncity] = cdist + ndist;
                pq.push(make_pair(dist[ncity],ncity));
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> M >> K;
    vector<int> market;
    for(int i = 0;i < K;i++) {
        int k;
        cin >> k;
        market.push_back(k-1);
    }
    vector<vector<pair<int,int>>> map(N);
    for(int i = 0;i < M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        map.at(a-1).push_back(make_pair(b-1,c));
        map.at(b-1).push_back(make_pair(a-1,c));
    }
    vector<vector<int>> dajkmap;
    for(int k : market) {
        dajkmap.push_back(dijk(k,map));
    }
    
    if(K == 1) {
        int minElement = INT_MAX;
        for(int cost : dajkmap[0]) {
            if(cost != 0 && cost < minElement) minElement = cost;
        }
        cout << 2*minElement << "\n";
        return 0;
    }

    int answer = INT_MAX;
    for(int first = 0; first < K-1; first++) {
        for(int last = first+1; last < K; last++) {
            //build home - first - ... - last - home
            int startCity = market[first];
            int endCity = market[last];

            //home_first + last_home
            int minHome = INT_MAX;
            for(int city = 0; city < N;city++) {
                if(find(market.begin(),market.end(),city) != market.end()) continue;
                int current = dajkmap[first][city] + dajkmap[last][city];
                if(current < minHome) minHome = current;
            }

            //intermarket
            int minInter = INT_MAX;
            
            if(K==2) {
                minInter = dajkmap[first][market[last]];
            } else if(K == 3) {
                int other = 0;
                for(int m : market) {
                     if(m != startCity && m != endCity) other = m;
                }
                minInter = dajkmap[first][other] + dajkmap[last][other];
            } 
            else {
                vector<int> others;
                for(int m = 0;m < K;m++) {
                    if(m != first && m != last) others.push_back(m);
                }
                sort(others.begin(), others.end());
                
                do {
                    int current = dajkmap[first][market[others[0]]] + dajkmap[last][market[others.back()]];
                    for(int i = 0; i < others.size() - 1;i++) {
                        current += dajkmap[others[i]][market[others[i+1]]];
                    }
                    if(current < minInter) minInter = current;
                } while(next_permutation(others.begin(),others.end()));
            }
            
            
            //update answer
            if(answer > minHome + minInter) answer = minHome + minInter;
        }
    }

    cout << answer << "\n";
    return 0;
}