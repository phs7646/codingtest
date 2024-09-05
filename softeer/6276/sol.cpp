#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pp;
pp moves[] = {{1,0},{-1,0},{0,1},{0,-1}};
int N;
int N2;
int N3;
vector<vector<int>> appendix;
int answer;

void adjust(vector<vector<int>>& map,vector<int>& numused, int col) {
    //give gravity to jth column
    vector<int> remain;
    for(int i = 0;i < N;i++) if(map[i][col] > 0) remain.emplace_back(map[i][col]);
    for(int index = 0;index < N;index++) {
        if(index < remain.size()) map[index][col] = remain[index];
        else {
            map[index][col] = appendix[numused[col]][col];
            numused[col]++;
        }
    }
}

void dfs(vector<vector<int>>& map, vector<int>& numused, int moved,int cur) {
    //호출은 새로운 map과 numused를 만들어서 넘길것
    vector<vector<bool>> visited(N,vector<bool>(N)); //bfs용 visitied
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(visited[i][j]) continue;
            
            
            if(moved == 2) {
                //정답 계산
                visited[i][j] = true;
                int color = map[i][j];
                int count = 1;
                int i1 = i, i2 = i, j1 = j, j2 = j;
                queue<pp> q; q.emplace(i,j);
                while(!q.empty()) {
                    pp cur = q.front();q.pop();
                    for(pp move : moves) {
                        int ni = cur.first + move.first;
                        int nj = cur.second + move.second;
                        if(0 > ni || ni >= N || 0 > nj || nj >= N) continue;
                        if(visited[ni][nj]) continue;
                        if(map[ni][nj] != color) continue;
                        //add
                        visited[ni][nj] = true;
                        i1 = min(i1,ni);
                        i2 = max(i2,ni);
                        j1 = min(j1,nj);
                        j2 = max(j2,nj);
                        count++;
                        q.emplace(ni,nj);
                    }
                }
                int newCur = cur + count + (j2-j1+1)*(i2-i1+1);
                answer = max(answer,newCur);
                continue;
            }
            //케이스 생성
            vector<vector<int>> newmap(map);
            visited[i][j] = true;
            int color = newmap[i][j];
            newmap[i][j] = 0;
            int count = 1;
            int i1 = i, i2 = i, j1 = j, j2 = j;
            queue<pp> q; q.emplace(i,j);
            while(!q.empty()) {
                pp cur = q.front();q.pop();
                for(pp move : moves) {
                    int ni = cur.first + move.first;
                    int nj = cur.second + move.second;
                    if(0 > ni || ni >= N || 0 > nj || nj >= N) continue;
                    if(visited[ni][nj]) continue;
                    if(newmap[ni][nj] != color) continue;
                    //add
                    visited[ni][nj] = true;
                    newmap[ni][nj] = 0;
                    i1 = min(i1,ni);
                    i2 = max(i2,ni);
                    j1 = min(j1,nj);
                    j2 = max(j2,nj);
                    count++;
                    q.emplace(ni,nj);
                }
            }
            int newCur = cur + count + (j2-j1+1)*(i2-i1+1);
            if(moved == 2) {
                answer = max(answer,newCur);
                continue;
            }
            vector<int> newnumused(numused);
            for(int _j = j1; _j <= j2; _j++) adjust(newmap,newnumused,_j);
            dfs(newmap,newnumused,moved+1,newCur);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //Input
    cin >> N;
    N2 = 2*N;
    N3 = 3*N;
    vector<vector<int>> map = vector<vector<int>>(N,vector<int>(N));
    appendix = vector<vector<int>>(N2,vector<int>(N));
    for(int i = 0;i < N2;i++) {
        for(int j = 0;j < N;j++) cin >> appendix[N2-i-1][j];
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) cin >> map[N-i-1][j];
    }
    vector<int> numused(N);
    dfs(map,numused,0,0);
    cout << answer;

    return 0;
}