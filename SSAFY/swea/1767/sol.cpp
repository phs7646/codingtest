#include<iostream>

using namespace std;

int map[12][12];
pair<int,int> corePos[12];
bool corePossib[12][4]; //상우하좌 순서로 연결이 가능한지 체크
bool used[12];
int numCore;
int N;
int answer;
int answer_num;
int cur_num;
int evaluatePossib(int core) {
    int ret = 4;
    //core의 possib 계산하기
    //상하좌우 순으로 가능한지 체크하기
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
    for(int k = 0;k < x;k++) if(map[k][x] > 0) {
        corePossib[core][2] = false;
        ret--;
        break;
    }
    return ret;
}

void backtrack() {
    //possib이 0인 케이스가 있으면 바로 리턴
    //possib이 가장 작은 케이스를 타겟으로 설정. 타겟의 가능한 방향 dfs
    int target = -1;
    int targetCount = 5;
    for(int i = 0;i < numCore;i++) {
        if(used[i]) continue;
        int curCount = evaluatePossib(i);
        if(curCount == 0) continue;
        if(curCount < targetCount) {
            target = i;
            targetCount = curCount;
        }
    }
    if(target == -1) {
        //끝났다...
        if(cur_num < answer_num) return;
        int cur = 0;
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) if(map[i][j] == 2) cur++;
        if(cur_num > answer_num || (cur_num == answer_num && cur < answer)) {
            answer = cur;
            answer_num = cur_num;
            cout << "Update Occured! to " << answer << endl;
            for(int i = 0;i < N;i++) {
                for(int j = 0;j < N;j++) {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }
        }
        return;
    }
    //타겟 설정 완료
    used[target] = true;
    cur_num++;
    int y = corePos[target].first;
    int x = corePos[target].second;
    for(int dir = 0;dir < 4;dir++) {
        if(!corePossib[target][dir]) continue;
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
        //dfs
        backtrack();

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
    //선택하지않고
    cur_num--;
    backtrack();
}

int main() {
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        cin >> N;
        numCore = 0;
        answer = 2100000000;
        answer_num = 0;
        cur_num = 0;
        // initialize map
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
            cin >> map[i][j];
            if(map[i][j] == 1 && i != 0 && i != N-1 && j != 0 && j != N-1) {
                //가장자리에 있지 않은 코어 등록
                corePos[numCore++] = {i,j};
            }
        }
        //initialize used
        fill(used,used+12,false);
        //backtrack start
        backtrack();
        //print
        cout << answer << endl;
        cout << answer_num << endl;
    }

    return 0;
}