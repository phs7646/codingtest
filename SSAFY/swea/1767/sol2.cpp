#include<iostream>

using namespace std;

int map[12][12];
pair<int,int> corePos[12];
bool corePossib[12][4]; //상우하좌 순서로 연결이 가능한지 체크
bool connected[12];
int numCore;
int N;
int answer;
int answer_connected;
int evaluatePossib(int core) {
    int ret = 4;
    //core의 possib 계산하기
    //상우하좌 순으로 가능한지 체크하기
    int y = corePos[core].first;
    int x = corePos[core].second;
    //상. 윗줄에 아무것도 없어야함
    corePossib[core][0] = true;
    for(int k = 0;k < y;k++) if(map[k][x] > 0) {
        corePossib[core][0] = false;
        ret--;
        break;
    }
    //우. 오른쪽에 아무것도 없어야함
    corePossib[core][1] = true;
    for(int k = x+1;k < N;k++) if(map[y][k] > 0) {
        corePossib[core][1] = false;
        ret--;
        break;
    }
    //하. 아래쪽에 아무것도 없어야함
    corePossib[core][2] = true;
    for(int k = y+1; k < N;k++) if(map[k][x] > 0) {
        corePossib[core][2] = false;
        ret--;
        break;
    }
    //좌. 왼쪽에 아무것도 없어야함
    corePossib[core][3] = true;
    for(int k = 0;k < x;k++) if(map[y][k] > 0) {
        corePossib[core][3] = false;
        ret--;
        break;
    }
    return ret;
}

void backtrack(int core) {
    //탈출조건
    if(core == numCore) {
        //end
        int numConnected = 0;
        for(int i = 0;i < numCore;i++) if(connected[i]) numConnected++;
        int cur = 0;
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) if(map[i][j] == 2) cur++;
        if(numConnected > answer_connected || (numConnected == answer_connected && cur < answer)) {
            answer = cur;
            answer_connected = numConnected;
        }
        return;
    }
    //남은거 다연결해도 모자란지 체크
    int maxConnected = numCore;
    for(int i = 0;i < core;i++) if(!connected[i]) maxConnected--;
    if(maxConnected < answer_connected) return;
    //core의 상태를 정하자
    int y = corePos[core].first;
    int x = corePos[core].second;
    evaluatePossib(core);
    connected[core] = true;
    for(int dir = 0;dir < 4;dir++) {
        if(!corePossib[core][dir]) continue;
        //cout << core << "를 " << dir << "방향으로 결정! \n";
        //dir방향으로 occupy
        if(dir == 0) {
            for(int k = 0;k < y;k++) map[k][x] = 2;
        } else if(dir == 1) {
            for(int k = x+1;k < N;k++) map[y][k] = 2;
        } else if(dir == 2) {
            for(int k = y+1;k < N;k++) map[k][x] = 2;
        } else {
            for(int k = 0;k < x;k++) map[y][k] = 2;
        }
        backtrack(core+1);
        //dir방향으로 unoccupy
        if(dir == 0) {
            for(int k = 0;k < y;k++) map[k][x] = 0;
        } else if(dir == 1) {
            for(int k = x+1;k < N;k++) map[y][k] = 0;
        } else if(dir == 2) {
            for(int k = y+1;k < N;k++) map[k][x] = 0;
        } else {
            for(int k = 0;k < x;k++) map[y][k] = 0;
        }
    }
    connected[core] = false;
    backtrack(core+1);

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        cin >> N;
        numCore = 0;
        answer = 2100000000;
        answer_connected = 0;
        // initialize map
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
            cin >> map[i][j];
            if(map[i][j] == 1 && i != 0 && i != N-1 && j != 0 && j != N-1) {
                //가장자리에 있지 않은 코어 등록
                corePos[numCore++] = {i,j};
            }
        }
        //initialize used
        fill(connected,connected+12,false);
        //backtrack start
        backtrack(0);
        //print
        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}