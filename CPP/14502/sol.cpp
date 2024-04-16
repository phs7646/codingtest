#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int MAP[8][8];
int N,M;
vector<pair<int,int>> virus;
vector<pair<int,int>> zero;
int ans;

void BFS() {
    int m[8][8];
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++) 
            m[i][j] = MAP[i][j];
    queue<pair<int,int>> q;
    for(pair<int,int> p : virus) {
        q.push(p);
    }
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        if(y+1 < N && m[y+1][x] == 0) {
            m[y+1][x] = 2;
            q.push(make_pair(y+1,x));
        }
        if(y-1 >= 0 && m[y-1][x] == 0) {
            m[y-1][x] = 2;
            q.push(make_pair(y-1,x));
        }
        if(x+1 < M && m[y][x+1] == 0) {
            m[y][x+1] = 2;
            q.push(make_pair(y,x+1));
        }
        if(x-1 >= 0 && m[y][x-1] == 0) {
            m[y][x-1] = 2;
            q.push(make_pair(y,x-1));
        }
    }
    int count = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            if(m[i][j] == 0) count++;
        }
    }
    if(ans < count) {
        ans = count;
        /*
        cout << ans << " MAP\n";
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < M;j++) {
                cout << m[i][j] << " ";
            }
            cout<< "\n";
        }
        */
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            cin >> MAP[i][j];
            if(MAP[i][j] == 0) zero.push_back(make_pair(i,j));
            else if(MAP[i][j] == 2) virus.push_back(make_pair(i,j));
        }
    }
    int num_zero = zero.size();
    ans = 0;
    for(int i = 0;i < num_zero-2;i++) {
        pair<int,int> first = zero.at(i);
        MAP[first.first][first.second] = 1;
        for(int j = i+1;j < num_zero-1;j++) {
            pair<int,int> second = zero.at(j);
            MAP[second.first][second.second] = 1;
            for(int k = j+1;k < num_zero;k++) {
                pair<int,int> third = zero.at(k);
                MAP[third.first][third.second] = 1;
                BFS();
                MAP[third.first][third.second] = 0;
            }
            MAP[second.first][second.second] = 0;
        }
        MAP[first.first][first.second] = 0;
    }
    cout << ans << "\n";
    return 0;
}