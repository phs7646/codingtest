#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int adj[5][5];
    int v[5];
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int N; cin >> N;
        int answer_min = N, answer_max = 1;
        for(int i = 0; i < N; i++) cin >> v[i];
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                adj[i][j] = -1; 
            }
        }
        
        // Build adj
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == j) continue;
                if(v[i] == v[j]) continue;
                double t = double(j - i) / double(v[i] - v[j]);
                if(t > 0) adj[i][j] = t;
            }
        }

        // Search
        queue<pair<int, double>> q;
        for(int first = 0; first < N; first++) {
            vector<double> meet(N, -1);
            meet[first] = 0;
            q.push({first, 0});
            while(!q.empty()) {
                auto p = q.front();
                q.pop();
                int cur = p.first;
                if(p.second != meet[cur]) continue;
                // cur -> others propagation
                for(int i = 0; i < N; i++) {
                    if(i == cur) continue;
                    if(adj[cur][i] == -1) continue;
                    if(meet[i] == -1 || (meet[cur] <= adj[cur][i] && meet[i] > adj[cur][i])) {
                        meet[i] = adj[cur][i];
                        q.push({i, meet[i]});
                    }
                }
            }
            int num = 0;
            for(double n : meet) if(n != -1) num++;
            answer_max = max(answer_max, num);
            answer_min = min(answer_min, num);
        }
        cout << answer_min << " " << answer_max << "\n";
    }
    return 0;
}
