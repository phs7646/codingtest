#include<iostream>
#include<string>
#include<queue>
#include<vector>
#define debug 0
using namespace std;
int K,M;
int map[5][5];
int supply[300];
int supplyIdx = 0;
pair<int,int> moves[] = {{0,1},{1,0},{-1,0},{0,-1}};
void printMap(string s) {
    cout << s << endl;
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
} 
void rotate(pair<int,int> core) {
    //core을 중심으로 90도 회전하기
    int backup[3][3] = {{0}};
    int y = core.first-1;
    int x = core.second-1;
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            backup[i][j] = map[y+i][x+j];
        }
    }
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            map[y+j][x+2-i] = backup[i][j];
        }
    }
}
int getFirstScore() {
    //bfs로 현재 상태에서 1차 획득 점수 조사
    vector<vector<bool>> visited(5,vector<bool>(5));
    int ret = 0;
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) {
            if(visited[i][j]) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = true;
            int count = 1;
            int target = map[i][j];
            while(!q.empty()) {
                pair<int,int> node = q.front();q.pop();
                for(int m = 0;m < 4;m++) {
                    int y = node.first + moves[m].first;
                    int x = node.second + moves[m].second;
                    if(0 <= x && x < 5 && 0 <= y && y < 5 && !visited[y][x] && map[y][x] == target) {
                        q.push({y,x});
                        visited[y][x] = true;
                        count++;
                    }
                }
            }
            if(count >= 3) ret += count;
        }
    }
    return ret;
}

int getScore() {
    //현재 상황에서 유물 획득하고 채우기
    int ret = 0;
    vector<vector<bool>> visited(5,vector<bool>(5));
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) {
            if(visited[i][j]) continue;
            queue<pair<int,int>> q;
            queue<pair<int,int>> history;
            q.push({i,j});
            visited[i][j] = true;
            int count = 1;
            int target = map[i][j];
            while(!q.empty()) {
                pair<int,int> node = q.front();q.pop();history.push(node);
                for(int m = 0;m < 4;m++) {
                    int y = node.first + moves[m].first;
                    int x = node.second + moves[m].second;
                    if(0 <= x && x < 5 && 0 <= y && y < 5 && !visited[y][x] && map[y][x] == target) {
                        q.push({y,x});
                        visited[y][x] = true;
                        count++;
                    }
                }
            }
            if(count >= 3) {
                ret += count;
                while(!history.empty()) {
                    pair<int,int> node = history.front(); history.pop();
                    map[node.first][node.second] = 0;
                }
            }
        }
    } //bfs 완료
    if(ret == 0) return 0;
    //채우기
    for(int j = 0;j < 5;j++) {
        for(int i = 4;i >= 0;i--) {
            if(map[i][j] == 0) {
                map[i][j] = supply[supplyIdx++];
            }
        }
    }
    return ret;
}

int main() {
    cin >> K >> M;
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0;i < M;i++) cin >> supply[i];
    for(int k = 0;k < K;k++) {
        //반복 시작
        //최대 점수 찾기
        int max_score = 0; //1차 획득 점수만 저장
        int max_rotate = -1;
        pair<int,int> max_node;

        for(int j = 1;j <= 3;j++) {
            for(int i = 1;i <= 3;i++) {
                //i,j에서 돌려보기
                for(int r = 1;r <= 3;r++) {
                    rotate({i,j}); //회전
                    int score = getFirstScore(); //1차 획득 점수
                    //score, r, j, i의 쌍 생성. 업데이트 필요시 업데이트
                    if(score > max_score ||
                    (score == max_score && r < max_rotate)) {
                        //업데이트 필요
                        max_score = score;
                        max_rotate = r;
                        max_node = {i,j};
                    }
                }
                //원상복구
                rotate({i,j});
            }
        }
        //탐색 종료
        if(debug) cout << max_node.first << " " << max_node.second << "를 선택 : "<< max_score <<"\n";
        //회전 시키기
        for(int r = 0;r < max_rotate;r++) rotate(max_node);
        //점수 획득하기
        int total = 0;
        while(true) {
            int get = getScore();
            if(debug) {
                cout << "점수 " << get << "획득 !\n";
                printMap("점수 획득 후");
            }
            if(get == 0) break;
            total += get; 
        }
        if(total == 0) return 0;
        cout << total << " ";
    }
    return 0;
}