#include<queue>
#include<iostream>
#include<vector>

using namespace std;
typedef pair<int,int> pp;

int N;
int map[20][20];
pp moves[] = {{-1,0},{1,0},{0,-1},{0,1}};

//상어의 상태
int cury,curx;
int cursize = 2;
int cureat = 0;

bool isValid(int i,int j) {
    if(i < 0 || j < 0) return false;
    if(i >= N || j >= N) return false;
    return true;
}

int main() {
    //input
    cin >> N;
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
        cin >> map[i][j];
        if(map[i][j] == 9) {
            cury = i; curx = j;map[i][j] = 0;
        }
    }
    
    //logic
    int time = 0;
    while(true) {
        //find prey : bfs
        int targety=-1,targetx=-1;
        queue<pp> q; q.emplace(cury,curx);
        vector<vector<bool>> visited(N,vector<bool>(N));
        visited[cury][curx] = true;
        int dist = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int _ = 0; _ < qSize; _++) {
                pp p = q.front(); q.pop();
                for(pp move : moves) { 
                    int ni = p.first + move.first;
                    int nj = p.second + move.second;
                    if(!isValid(ni,nj)) continue;
                    if(visited[ni][nj]) continue;
                    if(map[ni][nj] > cursize) continue;
                    visited[ni][nj] = true;
                    if(map[ni][nj] > 0 && map[ni][nj] < cursize) {
                        //found target
                        if(targety == -1) {
                            targety = ni;
                            targetx = nj;
                        } else if(targety > ni || (targety == ni && targetx > nj)) {
                            targety = ni;
                            targetx = nj;
                        }
                    } else {
                        //just move
                        q.emplace(ni,nj);
                    }
                }
            }
            dist++;
            if(targety !=-1) break;
        }
        //bfs end!
        if(targety == -1) break; //end

        //go and eat
        time += dist;
        cury = targety;
        curx = targetx;
        cureat++;
        if(cursize == cureat) {
            cursize++;
            cureat=0;
        }
        map[targety][targetx] = 0;
    }
    cout << time;
    return 0;
}