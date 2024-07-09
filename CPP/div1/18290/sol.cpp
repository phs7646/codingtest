#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> board(10,vector<int>(10));
vector<vector<bool>> used(10,vector<bool>(10));
int N,M,K;
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
int answer = INT_MIN;
int current = 0;
void dfs(int prevy,int prevx, int pick) {
    if(pick == 0) {
        //cout << "current : " << current << endl;
        answer = max(answer,current);
        return;
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            if(i < prevy ||  (i == prevy && j <= prevx)) continue;
            if(used[i][j] == false) {
                //pick i,j
                //cout << "pick " << i << " " << j << "\n";
                used[i][j] = true;
                current += board[i][j];
                vector<pair<int,int>> locked;
                for(int k = 0;k < 4;k++) {
                    int newi = i + moves[k].first;
                    int newj = j + moves[k].second;
                    if(0 <= newi && newi < N && 0 <= newj && newj < M && used[newi][newj] == false) {
                        used[newi][newj] = true;
                        locked.push_back({newi,newj});
                    }
                }
                dfs(i,j,pick-1);
                //cout << "unpick " << i << " " << j << "\n";
                current -= board[i][j];
                used[i][j] = false;
                for(auto pair : locked) {
                    used[pair.first][pair.second] = false;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) cin >> board[i][j];
    dfs(-1,-1,K);
    cout << answer;
    return 0;
}