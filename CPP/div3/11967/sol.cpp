#include<iostream>
#include<queue>
#include<vector>



using namespace std;
int main() {
    int N,M; cin >> N >> M;
    vector<vector<vector<pair<int,int>>>> buttons(N+1,vector<vector<pair<int,int>>>(N+1));
    for(int m = 0;m < M;m++) {
        int x,y,a,b; cin >> x >> y >> a >> b;
        buttons[x][y].emplace_back(a,b);
    }
    vector<vector<bool>> visited(N+1,vector<bool>(N+1));
    vector<vector<bool>> canvisit(N+1,vector<bool>(N+1));
    vector<vector<bool>> lighted(N+1,vector<bool>(N+1));
    queue<pair<int,int>> q;
    visited[1][1] = true;
    canvisit[1][1] = true;
    lighted[1][1] = true;
    pair<int,int> moves[] = {{0,1},{1,0},{0,-1},{-1,0}};
    q.emplace(1,1);
    while(!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        //cout << "visit " << p.first << " " << p.second << endl;
        //p를 방문한다
        //can visit을 업데이트한다 이 때 방문안하고 불이 켜진 방이 있다면 queue에 추가
        for(int d = 0;d < 4;d++) {
            int y = p.first + moves[d].first;
            int x = p.second + moves[d].second;
            if(y < 1 || y > N || x < 1 || x > N) continue;
            canvisit[y][x] = true;
            if(lighted[y][x] && !visited[y][x]) {
                visited[y][x] = true;
                q.emplace(y,x);
            }
        }
        //버튼을 전부 눌러서 불을킨다. 불이 켜진방이 can visit이라면 queue에 추가
        for(pair<int,int> btn : buttons[p.first][p.second]) {
            if(lighted[btn.first][btn.second]) continue;
            //불을 켠다
            lighted[btn.first][btn.second] = true;
            if(canvisit[btn.first][btn.second]) {
                //큐에 추가
                visited[btn.first][btn.second] = true;
                q.push(btn);
            }
        }
    }
    int answer = 0;
    for(int i = 1;i <= N;i++) for(int j = 1;j <= N;j++) if(lighted[i][j]) answer++;
    cout << answer;
    return 0;
}