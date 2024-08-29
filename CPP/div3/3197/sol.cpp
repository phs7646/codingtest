#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pp;

int R,C;
int map[1500][1500];
bool visited[1500][1500];
pp root[1500][1500]; //{-1,-1} : root
pp moves[] = {{0,1},{1,0},{0,-1},{-1,0}};


bool isValid(int i,int j) {
    if(0 > i || i >= R || 0 > j || j >= C) return false;
    return true;
}
bool isValid(pp p) {
    return isValid(p.first,p.second);
}

pp findRoot(pp p) {
    if(root[p.first][p.second].first == -1) return p;
    return root[p.first][p.second] = findRoot(root[p.first][p.second]);
}
void deb(pp A, pp B) {
    cout << "Union ";
    cout << "(" << A.first  <<"," << A.second << ") ";
    cout << "(" << B.first  <<"," << B.second << ") " << endl;
}

void _union(pp A,pp B) {
    //deb(A,B);
    pp rootA = findRoot(A);
    pp rootB = findRoot(B);
    if(rootA == rootB) return;
    root[rootB.first][rootB.second] = rootA;
}


int main() {
    cin >> R >> C;
    vector<pp> L;
    for(int i = 0;i < R;i++) {
        string s; cin >> s;
        for(int j = 0;j < C;j++) {
            root[i][j] = {-1,-1};
            if(s[j]=='X') map[i][j] = 1;
            else if(s[j]=='L') L.emplace_back(i,j);
        }
    }
    //initial bfs : build initial union and queue
    queue<pp> todoQ;
    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            if(visited[i][j]) continue;
            //bfs start
            queue<pp> q; q.emplace(i,j);
            visited[i][j] = true;
            while(!q.empty()) {
                pp p = q.front(); q.pop();
                for(pp move : moves) {
                    int ni = p.first + move.first;
                    int nj = p.second + move.second;
                    if(!isValid(ni,nj)) continue;
                    if(visited[ni][nj]) continue;
                    visited[ni][nj] = true;
                    if(map[ni][nj] == 0) {
                        _union(p,{ni,nj});
                        q.emplace(ni,nj);
                    } else {
                        todoQ.emplace(ni,nj);
                    }
                }
            }
        }
    }

    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            if(map[i][j] == 1) cout << "(---) ";
            else {
                pp r = findRoot({i,j});
                cout << "(" << r.first <<","<<r.second<<") ";
            }
            
        }
        cout << endl;
    }
    if(findRoot(L[0]) == findRoot(L[1])) {
        cout << 0;
        return 0;
    }

    return 0;
}