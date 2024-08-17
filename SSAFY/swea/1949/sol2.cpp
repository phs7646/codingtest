#include<iostream>
#include<vector>
using namespace std;

int board[8][8];
int N,K;
int answer = 0;
int cur = 0;
bool visited[8][8];
pair<int,int> moves[] = {{0,1},{1,0},{0,-1},{-1,0}};
bool constructed;

void dfs(int i,int j) {
    //지금 cur_val 부터 전부 고르면 constructed 인 경우 cur_val-1 ~ 1 까지 골라짐
    //!constructed인 경우 curval-1 ~ 0까지 골라짐
    int max_count = constructed ? board[i][j]-1 : board[i][j];
    if(max_count+cur < answer) return; //전부 다 골라도 max보다 적음
    answer = max(answer,cur);
    for(int d = 0;d < 4;d++) {
        int _i = i + moves[d].first;
        int _j = j + moves[d].second;
        if(0 > _i || _i >= N || 0 > _j || _j >= N) continue;
        if(visited[_i][_j]) continue;
        if(board[i][j] > board[_i][_j]) {
            //can visit
            cur++;
            visited[_i][_j] = true;
            dfs(_i,_j);
            visited[_i][_j] = false;
            cur--;
        } else if(!constructed && board[_i][_j] - K < board[i][j]) {
            //construct and go on
            constructed = true;
            int tmp = board[_i][_j];
            board[_i][_j] = board[i][j] - 1;
            visited[_i][_j] = true;
            cur++;
            dfs(_i,_j);
            cur--;
            visited[_i][_j] = false;
            board[_i][_j] = tmp; //restore
            constructed = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        //initialize
        answer = 0;
        cur = 0;
        cin >> N;
        cin >> K;
        int max_val = 0;
        vector<pair<int,int>> v;
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
            cin>>board[i][j];
            if(board[i][j] > max_val) {
                max_val = board[i][j];
                v.clear();
                v.emplace_back(i,j);
            } else if(board[i][j] == max_val) v.emplace_back(i,j);
        }
        for(pair<int,int> p : v) {
            cur = 1;
            visited[p.first][p.second] = true;
            dfs(p.first,p.second);
            visited[p.first][p.second] = false;
        }
        cout << '#' << t << " " << answer << "\n";
    }
    return 0;
}