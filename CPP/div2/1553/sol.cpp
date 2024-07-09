#include<iostream>
#include<vector>
#include<string>

using namespace std;
int N = 8,M = 7;
vector<vector<int>> board(N,vector<int>(M));
vector<vector<bool>> visited(N,vector<bool>(M));
vector<vector<bool>> piece(7,vector<bool>(7));

pair<int,int> next(pair<int,int> p) {
    p.second++;
    if(p.second >= 7) {
        p.first++;
        p.second = 0;
    }
    return p;
}
int dfs(pair<int,int> cur) {
    //i,j부터 시작해서 빈칸을 탐색
    while(cur.first < 8 && visited[cur.first][cur.second]) {
        cur = next(cur);
    }
    if(cur.first >= 8) {
        //check if board is full
        bool flag = true;
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < M;j++) {
                if(!visited[i][j]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) return 1;
        else return 0;
    }
    int ret = 0;
    //오른쪽 케이스
    if(cur.second+1 < 7 && !visited[cur.first][cur.second+1]) {
        int left = board[cur.first][cur.second];
        int right = board[cur.first][cur.second+1];
        if(left > right) {
            int t = left;
            left = right;
            right = t;
        }
        if(!piece[left][right]) {
            piece[left][right] = true;
            visited[cur.first][cur.second] = true;
            visited[cur.first][cur.second+1] = true;
            ret += dfs(next({cur.first,cur.second+1}));
            piece[left][right] = false;
            visited[cur.first][cur.second] = false;
            visited[cur.first][cur.second+1] = false;
        }
    }
    //아래쪽 케이스
    if(cur.first+1 < 8 && !visited[cur.first+1][cur.second+1]) {
        int left = board[cur.first][cur.second];
        int right = board[cur.first+1][cur.second];
        if(left > right) {
            int t = left;
            left = right;
            right = t;
        }
        if(!piece[left][right]) {
            piece[left][right] = true;
            visited[cur.first][cur.second] = true;
            visited[cur.first+1][cur.second] = true;
            ret += dfs(next({cur.first,cur.second}));
            piece[left][right] = false;
            visited[cur.first][cur.second] = false;
            visited[cur.first+1][cur.second] = false;
        }
    }
    return ret;
}

int main() {
    vector<string> input(N);
    for(int i = 0;i < N;i++) cin >> input[i];
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            board[i][j] = input[i][j] - '0';
        }
    }
    cout << dfs({0,0});
    return 0;
}