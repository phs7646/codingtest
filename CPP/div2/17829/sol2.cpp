#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> pooling(vector<vector<int>>& v) {
    int N = v.size()/2;
    vector<vector<int>> ret(N,vector<int>(N));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            //[2*i,2*j] ~ [2*i+1,2*j+1]
            int _i = 2*i;
            int _j = 2*j;
            vector<int> t;
            t.push_back(v[_i][_j]);
            t.push_back(v[_i+1][_j]);
            t.push_back(v[_i][_j+1]);
            t.push_back(v[_i+1][_j+1]);
            sort(t.begin(),t.end());
            ret[i][j] = t[2];
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