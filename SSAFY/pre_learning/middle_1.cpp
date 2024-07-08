#include <iostream>
#include <vector>

using namespace std;

int main() {
    pair<int,int> plus_moves[] = {{-1,0},{1,0},{0,-1},{0,1}};
    pair<int,int> x_moves[] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        int N,M;
        cin >> N >> M;
        M--;
        vector<vector<int>> board(N,vector<int>(N));
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) cin >> board[i][j];
        int answer = 0;
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                //+
                int count = board[i][j];
                for(int k = 1;k <= M;k++) {
                    for(pair<int,int> p : plus_moves) {
                        int new_i = i + k*p.first;
                        int new_j = j + k*p.second;
                        if(0<=new_i && new_i < N && 0<=new_j && new_j<N) {
                            count+=board[new_i][new_j];
                        }
                    }
                }
                answer = max(answer,count);
                //X
                count = board[i][j];
                for(int k = 1;k <= M;k++) {
                    for(pair<int,int> p : x_moves) {
                        int new_i = i + k*p.first;
                        int new_j = j + k*p.second;
                        if(0<=new_i && new_i < N && 0<=new_j && new_j<N) {
                            count+=board[new_i][new_j];
                        }
                    }
                }
                answer = max(answer,count);
            }
        }
        cout << "#" << t+1 << " " << answer << "\n";
    }

    return 0;
}