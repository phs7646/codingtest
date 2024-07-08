#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(int argc, char** argv)
{
    pair<int,int> moves[] = {{0,1},{1,0},{0,-1},{-1,0}};
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        int N;
        cin >> N;
        vector<vector<int>> board(N,vector<int>(N));
        vector<vector<int>> dist(N,vector<int>(N,INT_MAX));
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) cin >> board[i][j];
        int sy,sx;
        cin >> sy >> sx;
        dist[sy][sx] = 0;
        int ey,ex;
        cin >> ey >> ex;
        vector<queue<pair<int,int>>> q(3);
        q[0].push({sy,sx});
        int step = 0;
        while(!q[0].empty() || !q[1].empty() || !q[2].empty()) {
            int idx = step%3;
            int qsize = q[idx].size();
            for(int i = 0;i < qsize;i++) {
                pair<int,int> cur = q[idx].front();
                q[idx].pop();
                for(auto move : moves) {
                    int ny = cur.first + move.first;
                    int nx = cur.second + move.second;
                    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    if(board[ny][nx] == 1) continue;
                    int new_step = step+1;
                    if(board[ny][nx] == 2) {
                        // %3이 0일때 갈 수 있음.
                        if(new_step%3 != 0) new_step += 3-new_step%3;
                    }
                    if(new_step < dist[ny][nx]) {
                        dist[ny][nx] = new_step;
                        q[new_step%3].push({ny,nx});
                    }
                }
            }
            step++;
        }
        int answer = dist[ey][ex] < INT_MAX ? dist[ey][ex] : -1;
        cout << "#" << t+1 << " " << answer << "\n";
        /*
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(dist[i][j] == INT_MAX) cout << 'x' << " ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
	return 0;
}