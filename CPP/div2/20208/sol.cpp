#include<iostream>
#include<vector>

using namespace std;
int N,M,H;
int starty,startx;
vector<pair<int,int>> milks;
vector<bool> used;
int answer = 0;
void dfs(int y,int x,int m,int count) {
    if(abs(starty-y) + abs(startx-x) <= m) {
        answer = max(answer,count);
    }
    for(int i = 0;i < milks.size();i++) {
        if(used[i]) continue;
        auto pair = milks[i];
        int dist = abs(y-pair.first) + abs(x-pair.second);
        if(dist > m) continue;
        //eat
        used[i] = true;
        dfs(pair.first,pair.second,m-dist+H,count+1);
        used[i] = false;
    }
}

int main() {
    cin >> N >> M >> H;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            int c;
            cin >> c;
            if(c == 1) {
                starty = i;
                startx = j;
            } else if(c == 2) {
                milks.push_back({i,j});
            }
        }
    }
    used.resize(milks.size());
    dfs(starty,startx,M,0);
    cout << answer;
    return 0;
}