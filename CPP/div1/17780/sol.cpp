//11:10

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,K;
int map[12][12];
//말의 정보 y,x,dir,pos
struct Horse {
    int y,x;
    int dir; //우 좌 상 하
};
typedef struct Horse horse;
horse horses[10];
//지도상의 정보
vector<int> now[12][12];

void printMap() {
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(now[i][j].empty()) cout << "-";
            for(int k : now[i][j]) {
                cout << k;
            }
            cout << " ";
        }
        cout << "\n";
    }
}

bool is_valid(int y,int x) {
    if(y < 0 || y >= N || x < 0 || x >= N) return false;
    return true;
}

int main() {
    cin >> N >> K;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0;i < K;i++) {
        cin >> horses[i].y >> horses[i].x >> horses[i].dir;
        horses[i].y--;
        horses[i].x--;
        now[horses[i].y][horses[i].x].push_back(i);
    }
    int count = 0;
    while(1) {
        if(count >= 1000) {
            cout<<-1<<"\n";
            exit(0);
        }
        //stage count
        for(int i = 0;i < K;i++) {
            //cout << "Stage : " << count << " Before " << i <<"\n";;
            //printMap();
            if(now[horses[i].y][horses[i].x].at(0) != i) continue; //don't move
            int y = horses[i].y;
            int x = horses[i].x;
            int new_y = y;
            int new_x = x;
            if(horses[i].dir == 1) new_x++;
            else if(horses[i].dir == 2) new_x--;
            else if(horses[i].dir == 3) new_y--;
            else if(horses[i].dir == 4) new_y++;
            if(!is_valid(new_y,new_x) || map[new_y][new_x] == 2) {
                //change direction
                if(horses[i].dir == 1) {
                    horses[i].dir = 2;
                    new_x-=2;
                }
                else if(horses[i].dir == 2) {
                    horses[i].dir = 1;
                    new_x+=2;
                }
                else if(horses[i].dir == 3) {
                    horses[i].dir = 4;
                    new_y+=2;
                }
                else if(horses[i].dir == 4) {
                    horses[i].dir = 3;
                    new_y-=2;
                }
                if(!is_valid(new_y,new_x) || map[new_y][new_x] == 2) continue; //don't move
            } 
            queue<int> coming;
            //reverse if need
            if(map[new_y][new_x] == 1) for(int i = now[y][x].size()-1; i >= 0 ;i--) coming.push(now[y][x].at(i));
            else for(int i = 0; i < now[y][x].size();i++) coming.push(now[y][x].at(i));
            while(!coming.empty()) {
                int i = coming.front();
                now[new_y][new_x].push_back(i);
                coming.pop();
                horses[i].y = new_y;
                horses[i].x = new_x;
            }
            if(now[new_y][new_x].size() >= 4) {
                cout << count+1 << "\n";
                exit(0);
            }
            now[y][x].clear();
        }
        count++;
    }

    return 0;
}