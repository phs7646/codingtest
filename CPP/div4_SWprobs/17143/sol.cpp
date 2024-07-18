#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
    int r;
    int c;
    int speed;
    int dir;
    int size;
} shark;


int R,C,M;

bool died[10000];
shark sharks[10000];
int map[100][100];

pair<int, int> move(shark& s) {
    if(s.dir == 1) s.r -= s.speed;
    else if(s.dir == 2) s.r += s.speed;
    else if(s.dir == 3) s.c += s.speed;
    else if (s.dir == 4) s.c -= s.speed;
    while(true) {
        //if need flip, then flip
        if(s.r < 0) {
            s.r = -1 * s.r;
            s.dir = 2;
        } else if(s.r >= R) {
            s.r = R-2 - (s.r-R);
            s.dir = 1;
        } else if(s.c < 0) {
            s.c = -1 * s.c;
            s.dir = 3;
        } else if(s.c >= C) {
            s.c = C-2 - (s.c-C);
            s.dir = 4;
        } else break;
    }
    return {s.r, s.c};
}


int main() {
    cin >> R >> C >> M;
    for(int i = 0;i < R;i++) for(int j = 0;j < C;j++) map[i][j] = -1;

    for(int i = 0;i < M;i++) {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].speed;
        cin >> sharks[i].dir >> sharks[i].size;
        sharks[i].r--;
        sharks[i].c--;
        /*
        if(sharks[i].dir == 1 || sharks[i].dir == 2) {
            sharks[i].speed %= R*2;
        } else {
            sharks[i].speed %= C*2;
        }
        */
        map[sharks[i].r][sharks[i].c] = i;
    }
    int fisher = -1;
    long long answer = 0;
    while(fisher < C-1) {
        //낚시꾼 이동
        fisher++;
        //해당 열의 가장 가까운 상어 잡기
        for(int r = 0;r < R;r++) {
            if(map[r][fisher] != -1) {
                int sh = map[r][fisher];
                answer += sharks[sh].size;
                died[sh] = true;
                break;
            }
        }
        //상어의 이동
        //map초기화
        for(int i = 0;i < R;i++) for(int j = 0;j < C;j++) map[i][j] = -1;
        //각상어의 새로운위치 업데이트
        for(int sh = 0;sh < M;sh++) {
            if(died[sh]) continue;
            pair<int,int> newloc = move(sharks[sh]);
            int r = newloc.first;
            int c = newloc.second;
            if(map[r][c] == -1) {
                map[r][c] = sh;
            } else {
                int ori_sh = map[r][c];
                //fight
                if(sharks[sh].size < sharks[ori_sh].size) {
                    died[sh] = true;
                } else {
                    died[ori_sh] = true;
                    map[r][c] = sh;
                }
            }
        }
    }
    cout << answer;

    return 0;
}
