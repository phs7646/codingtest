#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    double adj[5][5];
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
        for(int first = 0; first < N; first++) {
            vector<double> meet(N, -1);
            meet[first] = 0;
            queue<int> q;
            q.push(first);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                // cur -> others propagation
                for(int i = 0; i < N; i++) {
                    if(i == cur) continue;
                    if(adj[cur][i] == -1) continue;
                    if(meet[cur] > adj[cur][i]) continue; //can't propagate
                    if(meet[i] == -1 || meet[i] > adj[cur][i] ) {
                        meet[i] = adj[cur][i];
                        q.push(i);
                    }
                }
            }
            int num = 0;
            for(double n : meet) if(n >= 0) num++;
            answer_max = max(answer_max, num);
            answer_min = min(answer_min, num);
        }
        cout << answer_min << " " << answer_max << "\n";
    }
    return 0;
}
