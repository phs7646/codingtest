#include <iostream>
#include <queue>
#define INT_MAX 999999
using namespace std;
int N,M;
char map[500][500];
pair<int,int> start;
pair<int,int> goal;
queue<pair<int,int>> q;
int D[500][500];

void printMap() {
    cout << "Printing Map------------\n";
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            int c = D[i][j];
            if(c == INT_MAX) cout << "# ";
            else cout << c << " ";
        }
        cout << "\n";
    }
    cout << "------------------------\n";
}
void check_goal(int y,int x,int flip) {
    if(goal.first == y && goal.second == x) {
        cout << flip << "\n";
        exit(0);
    }
}
bool is_valid(int y,int x) {
    if(y < 0 || y >= N) return false;
    if(x < 0 || x >= M) return false;
    return true;
}
bool is_stable(int y,int x,bool gravity) {
    //if(!is_valid(y,x)) return false;
    if(gravity && (y == N-1 || map[y+1][x] != '#')) return false;
    else if(!gravity && (y == 0 || map[y-1][x] != '#')) return false;
    return true;
}

void travel(int y, int x, bool gravity, bool dir,int flip) { // gravity 1 : normal, 0 : flipped ,, dir 1 : right, 0 : left
    int new_x = dir?x+1:x-1;
    if(new_x < 0 || new_x >= M || map[y][new_x] == '#') return;

    //fall
    int new_y = y;
    while(is_valid(new_y,new_x) && !is_stable(new_y,new_x,gravity)) {
        check_goal(new_y,new_x,flip);
        if(gravity) new_y++;
        else new_y--;
    }
    if(!is_valid(new_y,new_x)) return;
    //found stable position
    if(D[new_y][new_x] > flip) {
        check_goal(new_y,new_x,flip);
        D[new_y][new_x] = flip;
        q.push(make_pair(new_y,new_x));
        if(new_y != y) travel(new_y,new_x,gravity,!dir,flip);
        travel(new_y,new_x,gravity,dir,flip);
    }
}

int main() {
    cin >> N >> M;
    
    //input and initialize
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            D[i][j] = INT_MAX;
            cin >> map[i][j];
            if(map[i][j] == 'C') {
                start = make_pair(i,j);
                D[i][j] = 0;
            } else if(map[i][j] == 'D') {
                goal = make_pair(i,j);
            }
        }
    }

    //edge case
    if(start == goal) {
        cout << "0\n";
        return 0;
    }
    if(start.first == N-1) {
        cout << "-1\n";
    }
    if(map[start.first+1][start.second] != '#') {
        //fall
        int new_y = start.first;
        while(is_valid(new_y,start.second) && !is_stable(new_y,start.second,true)) {
            check_goal(new_y,start.second,0);
            new_y++;
        }
        if(!is_valid(new_y,start.second)) {
            cout << "-1\n";
            return 0;
        }
        check_goal(new_y,start.second,0);
        D[new_y][start.second] = 0;
        start.first = new_y;
    }
    q.push(start);


    bool gravity = 1;
    travel(start.first,start.second,gravity,true,0);
    travel(start.first,start.second,gravity,true,1);

    int flip = 0;
    while(!q.empty()) {
        //cout << "Queue size : " << q.size() << "\n";
        //printMap();

        flip++;
        gravity = !gravity;
        int qsize = q.size();
        for(int i = 0;i < qsize;i++) {
            //pick one and flip
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            //fall
            int new_y = y;
            while(is_valid(new_y,x) && !is_stable(new_y,x,gravity)) {
                check_goal(new_y,x,flip);
                if(gravity) new_y++;
                else new_y--;
            }
            if(!is_valid(new_y,x)) continue;
            //found stable position
            if(D[new_y][x] > flip) {
                check_goal(new_y,x,flip);
                D[new_y][x] = flip;
            }
            travel(new_y,x,gravity,0,flip);
            travel(new_y,x,gravity,1,flip);
        }
    }
    cout << "-1\n";
    return 0;
}