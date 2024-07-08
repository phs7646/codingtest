#include<iostream>
#include<vector>

using namespace std;
int N,M;
vector<vector<int>> board(5,vector<int>(5));
vector<vector<bool>> visited(5,vector<bool>(5));
vector<vector<int>> shapes = {{1,2,0,1},{0,1,1,2},{1,0,2,1},{2,1,1,0}};
int cur = 0;
int answer = 0;

void dfs(int i,int j) {
    //cout << "Call " << i << " " << j << " " << cur << endl;
    answer = max(answer,cur);
    if(i >= N || j >= M) return;
    
    /*
    for(int a = 0; a < N;a++) {
        for(int b = 0;b < M;b++) {
            cout << visited[a][b] << " ";
        }
        cout << endl;
    }
    */
    
    int nexti = i;
    int nextj = j+1;
    if(nextj == M) {
        nexti++;
        nextj = 0;
    }

    //without nothing
    dfs(nexti,nextj);
    if(i == N-1 || j == M-1) return;

    bool flag;
    //add 4 shape
    for(auto shape : shapes) {
        flag = true;
        for(int a = 0;a < 2;a++)
            for(int b = 0;b < 2;b++)
                if(shape[a*2+b] && visited[i+a][j+b]) {
                    flag = false;
                }
        if(flag) {
            int tmp = 0;
            for(int a = 0;a < 2;a++)
                for(int b = 0;b < 2;b++)
                    if(shape[a*2+b]) {
                        visited[i+a][j+b] = true;
                        tmp += shape[a*2+b] * board[i+a][j+b];
                    }
            cur += tmp;
            dfs(nexti,nextj);
            cur -= tmp;
            for(int a = 0;a < 2;a++)
                for(int b = 0;b < 2;b++)
                    if(shape[a*2+b]) {
                        visited[i+a][j+b] = false;
                    }
        }
    }
    
}

int main() {
    cin >> N >> M;
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) cin >> board[i][j];
    if(N == 1 || M == 1) {
        cout << 0;
        return 0;
    }
    dfs(0,0);
    cout << answer;

    return 0;
}