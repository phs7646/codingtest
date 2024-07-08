#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> pooling(vector<vector<int>>& v) {
    int N = v.size()/2;
    vector<vector<int>> ret(N,vector<int>(N));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            //[2*i,2*j] ~ [2*i+1,2*j+1]
            int tmp1 = max(v[2*i][2*j],v[2*i+1][2*j]);
            int tmp2 = max(v[2*i][2*j+1],v[2*i+1][2*j+1]);
            ret[i][j] = min(tmp1,tmp2);
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> board(N,vector<int>(N));
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) cin >> board[i][j];
    while(board.size() > 1) board = pooling(board);
    cout << board[0][0];
    return 0;
}