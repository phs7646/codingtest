#include<iostream>
#include<queue>
using namespace std;

int debug = 0;
int R,C,K;
int map[74][71];
typedef struct {
    int c;
    int d;
    int y;
    int x;
} Golem;
Golem golems[1000];
bool visited[1000];
int window;
pair<int,int> checkDown[] = {{1,1},{1,-1},{2,0}};
pair<int,int> checkLeft[] = {{-1,-1},{0,-2},{1,-1},{1,-2},{2,-1}};
pair<int,int> checkRight[] = {{-1,1},{0,2},{1,1},{1,2},{2,1}};
pair<int,int> occupy[] = {{0,0},{1,0},{0,1},{-1,0},{0,-1}};
pair<int,int> moves[] = {{1,0},{0,1},{-1,0},{0,-1}};
bool isValid(int y,int x) {
    if(y < 1 || y > R+3 || x < 1 || x > C) return false;
    if(map[y][x] > -1) return false;
    return true;
}

int main() {
    cin >> R >> C >> K;
    //map initialize
    window = 0;
    for(int i = 1; i <= R+3;i++) for(int j = 1;j <= C;j++) map[i][j] = -1; 
    int answer = 0;
    for(int k = 0;k < K;k++) {
        cin >> golems[k].c >> golems[k].d;
        if(debug) cout << "Golem " << k << endl;
        golems[k].y = 2;
        golems[k].x = golems[k].c;
        while(true) {
            //move down
            bool available = true;
            for(int i = 0;i < 3;i++) {
                int _y = golems[k].y + checkDown[i].first;
                int _x = golems[k].x + checkDown[i].second;
                if(!isValid(_y,_x)) {
                    available = false;
                    break;
                }
            }
            if(available) {
                if(debug) cout << "moving down\n";
                golems[k].y++;
                continue;
            }
            //move left
            available = true;
            for(int i = 0;i < 5;i++) {
                int _y = golems[k].y + checkLeft[i].first;
                int _x = golems[k].x + checkLeft[i].second;
                if(!isValid(_y,_x)) {
                    available = false;
                    break;
                }
            }
            if(available) {
                if(debug) cout << "moving left\n";
                golems[k].y++;
                golems[k].x--;
                golems[k].d = (golems[k].d + 3)%4;
                continue;
            }
            //move right
            available = true;
            for(int i = 0;i < 5;i++) {
                int _y = golems[k].y + checkRight[i].first;
                int _x = golems[k].x + checkRight[i].second;
                if(!isValid(_y,_x)) {
                    available = false;
                    break;
                }
            }
            if(available) {
                if(debug) cout << "moving right\n";
                golems[k].y++;
                golems[k].x++;
                golems[k].d = (golems[k].d + 1)%4;
                continue;
            }
            break;//더이상 이동 불가능
        }
        //이동 완료.
        if(golems[k].y <= 4) {
            //꽉찼다..! 
            for(int i = 1;i <= R+3;i++) {
                for(int j = 1;j <= C;j++) {
                    map[i][j] = -1;
                }
            }
            window = k+1;
            if(debug) cout << "초기화!!\n";
            continue;
        }
        //occupy
        for(int i = 0;i < 5;i++) {
            map[golems[k].y + occupy[i].first][golems[k].x + occupy[i].second] = k;
        }
        if(debug) cout << "Golem " << k << " end : " << golems[k].y << " " << golems[k].x << " " << golems[k].d << endl;
        if(debug) {
            for(int i = 1;i <= R+3;i++) {
                for(int j = 1;j <= C;j++) {
                    if(map[i][j]==-1) cout << "* ";
                    else cout << map[i][j] << " ";
                }
                cout << endl;
            }
        }
        //move fairy
        int fairyend = golems[k].y+1;
        for(int w = window;w < k;w++) visited[w] = false;
        visited[k] = true;
        queue<int> q; q.push(k);
        while(!q.empty()) {
            int g = q.front(); q.pop();
            pair<int,int> exit = {golems[g].y,golems[g].x};
            if(golems[g].d == 0) exit.first--;
            else if(golems[g].d == 1) exit.second++;
            else if(golems[g].d == 2) exit.first++;
            else exit.second--;
            for(int m = 0;m < 4;m++) {
                int _y = exit.first + moves[m].first;
                int _x = exit.second + moves[m].second;
                if(_y < 1 || _y > R+3 || _x < 1 || _x > C) continue;
                int next = map[_y][_x];
                if(next != -1 && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    fairyend = fairyend < golems[next].y+1 ? golems[next].y+1 : fairyend;
                }
            }
        }
        if(fairyend < 3) return -1;
        if(debug) cout << (fairyend-3) << " 점을 얻었다!\n";
        //update
        answer += fairyend - 3;
    }
    cout << answer << endl;
    return 0;
}