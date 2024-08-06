#include<iostream>
#include<vector>
using namespace std;

int map[5][5];
bool visited[5][5];
pair<int,int> moves[] = {{0,1},{1,0},{0,-1},{-1,0}};
int eat = 0;
int answer = -1;
int cur_move = 0;
void dfs(pair<int,int> p) {
    if(eat == 3) {
        //update
        if(answer == -1 || answer > cur_move) {
            answer = cur_move;
        }
        return;
    }
    for(int d = 0;d < 4;d++) {
        int i = p.first + moves[d].first;
        int j = p.second + moves[d].second;
        if(0 <= i && i < 5 && 0 <= j && j < 5 && map[i][j] != -1 && !visited[i][j]) {
            //visit
            if(map[i][j] == 1) eat++;
            visited[i][j] = true;
            cur_move++;
            dfs({i,j});
            cur_move--;
            visited[i][j] = false;
            if(map[i][j] == 1) eat--;
        }
    }

}

int main() {
    for(int i = 0;i < 5;i++) for(int j = 0;j < 5;j++) cin >> map[i][j];
    int r,c; cin >> r >> c;
    visited[r][c]= true;
    dfs({r,c});
    cout << answer;
    return 0;
}