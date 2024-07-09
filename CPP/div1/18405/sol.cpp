#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    int N,K;
    cin >> N >> K;
    vector<vector<int>> map(N,vector<int>(N));
    vector<queue<pair<int,int>>> q(K+1);
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            int k;
            cin >> k;
            if(k != 0) {
                q[k].push({i,j});
                map[i][j] = k;
            }
        }
    }
    int S,X,Y;
    cin >> S >> X >> Y;
    for(int s = 0;s < S;s++) {
        for(int k = 1;k <= K;k++) {
            int size = q[k].size();
            for(int n = 0;n < size;n++) {
                auto pair = q[k].front();
                int i = pair.first;
                int j = pair.second;
                q[k].pop();
                for(auto move : moves) {
                    int new_i = i + move.first;
                    int new_j = j + move.second;
                    if(0 <= new_i && new_i < N && 0 <= new_j && new_j < N && map[new_i][new_j] == 0) {
                        q[k].push({new_i,new_j});
                        map[new_i][new_j] = k;
                    }
                }
            }
        }
    }
    cout << map[X-1][Y-1];
    return 0;
}