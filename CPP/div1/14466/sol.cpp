#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N,K,R;
vector<pair<int,int>> road[100][100];
bool cowmap[100][100];
bool visited[100][100];
queue<pair<int,int>> cows;
int num_visited = 0;


void dfs(int x,int y) {
    visited[x][y] = true;
    if(cowmap[x][y]) num_visited++;
    pair<int,int> dir[4] = {make_pair(x,y+1), make_pair(x,y-1), make_pair(x+1, y), make_pair(x-1,y)};
    for(pair<int,int> d : dir) {
        int a = d.first;
        int b = d.second;
        if(a < 0 || a >= N || b < 0 || b >= N) continue;
        if(visited[a][b]) continue;
        if(find(road[x][y].begin(),road[x][y].end(),make_pair(a,b)) != road[x][y].end()) continue;
        dfs(a,b);
    }
}

int main() {
    cin >> N >> K >> R;
    for(int i = 0; i < R;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        road[a][b].push_back(make_pair(c,d));
        road[c][d].push_back(make_pair(a,b));
    }
    for(int i = 0;i < K;i++) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        cowmap[x][y] = true;
        cows.push(make_pair(x,y));
    }

    int count = 0;
    
    while(!cows.empty()) {
        pair<int,int> cow = cows.front();
        cows.pop();
        if(visited[cow.first][cow.second]) continue;
        int old_num = num_visited;
        dfs(cow.first,cow.second);
        int current_cow = num_visited - old_num;
        count += current_cow * (K-current_cow);
    }

    cout << count/2 << "\n";
}