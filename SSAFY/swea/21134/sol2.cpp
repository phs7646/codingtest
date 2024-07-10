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
    for(int t = 1;t <= T;t++) {
        int N; cin >> N;
        int answer_min = N, answer_max = 1;
        for(int i = 0;i < N;i++) cin >> v[i];
        //build adj
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < i;j++) {
                if(v[i] >= v[j]) adj[i][j] = -1;
                else {
                    //i +v[i] t = j + v[j] t
                    adj[i][j] = double(i-j)/double(v[j]-v[i]);
                }
            }
        }
        for(int i = 0;i < N;i++) for(int j = 0;j < i;j++) adj[j][i] = adj[i][j];
        //search
        queue<pair<int,double>> q;
        for(int first = 0;first < N;first++) {
            vector<double> meet(N,-1);
            meet[first] = 0;
            q.push({first,0});
            while(!q.empty()) {
                auto p = q.front();
                q.pop();
                int cur = p.first;
                if(p.second != meet[cur]) continue;
                //cur -> others propagation
                for(int i = 0;i < N;i++) {
                    if(i == cur) continue;
                    if(adj[cur][i] == -1) continue;
                    double new_t = meet[cur] + adj[cur][i];
                    if(meet[i] == -1 || meet[i] > new_t) {
                        meet[i] = new_t;
                        q.push({i,meet[i]});
                    }
                }
            }
            int num = 0;
            for(int n : meet) if(n!=-1) num++;
            answer_max = max(answer_max,num);
            answer_min = min(answer_min,num);
        }
        cout << answer_min << " " << answer_max << "\n";
    }

    return 0;
}