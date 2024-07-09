#include<iostream>
#include<vector>

using namespace std;
int W,H;
vector<vector<int>> board(100,vector<int>(100));



void myPrint() {
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<int,int>> close(int i,int j) {
    vector<pair<int,int>> ret;
    int left = j-1;
    int right = j;
    if(i%2 == 0) {
        left++;right++;
    }
    if(i > 0) {
        if(left >= 0)ret.push_back({i-1,left});
        if(right < W)ret.push_back({i-1,right});
    }
    if(i+1 < H) {
        if(left >= 0)ret.push_back({i+1,left});
        if(right < W)ret.push_back({i+1,right});
    }
    if(j > 0) ret.push_back({i,j-1});
    if(j+1 < W) ret.push_back({i,j+1});
    return ret;
}

bool dfs_flag_outside;
void dfs(int i,int j) {
    if(board[i][j] != 0) return;
    board[i][j] = 4;
    if(i == 0 || i == H-1 || j == 0 || j == W-1) dfs_flag_outside = true;
    vector<pair<int,int>> closes = close(i,j);
    for(auto pair : closes) {
        if(board[pair.first][pair.second] == 0) dfs(pair.first,pair.second);
    }
}
int main() {
    cin >> W >> H;
    for(int i = 0;i < H;i++) for(int j = 0;j < W;j++) cin >> board[i][j];
    //1 : building, 2 : outside, 3:inside , 0 : need to check, 4 : checking

    //decide inside and outside
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            if(board[i][j] == 0) {
                dfs_flag_outside = false;
                dfs(i,j);
                for(int a = 0;a < H;a++) {
                    for(int b = 0;b < W;b++) {
                        if(board[a][b] == 4) {
                            board[a][b] = dfs_flag_outside?2:3;
                        }
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            if(board[i][j] != 1) continue;
            vector<pair<int,int>> closes = close(i,j);
            answer += 6 - closes.size();
            for(auto pair : closes) {
                if(board[pair.first][pair.second] == 2) answer++;
            }
        }
    }

    cout << answer;
    return 0;
}