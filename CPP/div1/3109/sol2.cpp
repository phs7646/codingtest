#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R,C;
int count = 0;
queue<pair<int,int>> q;

int main() {
    cin >> R >> C;
    vector<vector<bool>> map(R, vector<bool>(C, false));
    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            char c;
            cin >> c;
            if(c == 'x') map[i][j] = true;
        }
    }
    for(int r = 0;r < R;r++) q.push({r,0});

    for(int step = 1;step < C;step++) {
        cout << "step : " << step << ", qsize : " << q.size() << "\n";
        for(int r = 0;r < R;r++) {
            if(map[r][step]) continue;
            while(!q.empty()) {
                if(q.front().second == step) break;
                if(q.front().first < r-1) q.pop();
                else break;
            }
            if(q.empty()) break;
            if(q.front().first > r+1) continue;
            if(q.front().second == step-1) {
                q.pop();
                q.push({r,step});
            }
            
        }
        if(q.empty()) break;
        while(!q.empty() && q.front().second == step-1) q.pop();
    }
    cout << q.size();
    return 0;
}