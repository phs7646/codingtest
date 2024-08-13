#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int board[8][8];
int N;
int answer = 0;
int cur = 0;
bool visited[8][8];
pair<int,int> moves[] = {{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int i,int j) {
    answer = max(answer,cur);
    for(int d = 0;d < 4;d++) {
        int _i = i + moves[d].first;
        int _j = j + moves[d].second;
        if(0 <= _i && _i < N && 0 <= _j && _j < N) {
            if(!visited[_i][_j] && board[i][j] > board[_i][_j]) {
                //can visit
                cur++;
                visited[_i][_j] = true;
                dfs(_i,_j);
                visited[_i][_j] = false;
                cur--;
            }
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
        int K; cin >> K;
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
            cin>>board[i][j];
            visited[i][j] = false;
        }
        //build maxq
        vector<pair<int,int>> highs;
        int max_val = 0;
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(max_val < board[i][j]) {
                    max_val = board[i][j];
                    highs.clear();
                    highs.emplace_back(i,j);
                } else if(max_val == board[i][j]) {
                    highs.emplace_back(i,j);
                }
            }
        }

        for(int y = 0;y < N;y++) {
            for(int x = 0;x < N;x++) {
                for(int k = 1;k <= K;k++) {
                    board[y][x] -= k; //construct
                    //dfs for highest cell
                    for(pair<int,int> p : highs) {
                        visited[p.first][p.second] = true;
                        cur = 1;
                        dfs(p.first,p.second);
                        cur = 0;
                        visited[p.first][p.second] = false;
                    }
                    board[y][x] += k; //restore
                }
            }
        }
        //dfs for all cell without construct
        for(pair<int,int> p : highs) {
            visited[p.first][p.second] = true;
            cur = 1;
            dfs(p.first,p.second);
            cur = 0;
            visited[p.first][p.second] = false;
        }
        cout << '#' << t << " " << answer << "\n";
    }
    return 0;
}