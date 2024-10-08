#include <iostream>
#include <queue>
#define INT_MAX 999999
using namespace std;
int N,M;
char map[500][500];
pair<int,int> start;
pair<int,int> goal;
queue<pair<pair<int,int>,bool>> q;
int D[500][500][2]; //0 for flipped 1 for normal
void go_left(int y,int x,bool gravity,int flip);
void go_right(int y,int x,bool gravity,int flip);

void printMap() {
    cout << "gravity 1\n";
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            int c = D[i][j][1];
            if(c == INT_MAX) cout << "# ";
            else cout << c << " ";
        }
        cout<<"\n";
    }
    cout << "gravity 0\n";
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            int c = D[i][j][0];
            if(c == INT_MAX) cout << "# ";
            else cout << c << " ";
        }
        cout<<"\n";
    }
}

void go_left(int y,int x,bool gravity,int flip) {
    int left = x-1;
    if(left < 0 || map[y][left] == '#') return;
    int new_y = y;
    if(gravity) {
        while(new_y < N-1 && map[new_y+1][left] != '#') new_y++;
        if(new_y >= N-1) return;
    } else {
        while(new_y > 0 && map[new_y-1][left] != '#') new_y--;
        if(new_y <= 0) return; 
    }
    //record
    if(flip < D[new_y][left][gravity]) {
        D[new_y][left][gravity] = flip;
        q.push(make_pair(make_pair(new_y,left),gravity));
    }
    if(new_y != y) {
        go_right(new_y,left,gravity,flip);
    }
    go_left(new_y,left,gravity,flip);
}

void go_right(int y,int x,bool gravity,int flip) {
    int right = x+1;
    if(right < 0 || map[y][right] == '#') return;
    int new_y = y;
    if(gravity) {
        while(new_y < N-1 && map[new_y+1][right] != '#') new_y++;
        if(new_y >= N-1) return;
    } else {
        while(new_y > 0 && map[new_y-1][right] != '#') new_y--;
        if(new_y <= 0) return; 
    }
    
    //record
    if(gravity) {
        if(flip < D[new_y][right][1]) {
            D[new_y][right][1] = flip;
            q.push(make_pair(make_pair(new_y,right),gravity));
        }
    } else {
        if(flip < D[new_y][right][0]) {
            D[new_y][right][0] = flip;
            q.push(make_pair(make_pair(new_y,right),gravity));
        }
    }
    
    //go further
    if(new_y != y) {
        go_left(new_y,right,gravity,flip);
    }
    go_right(new_y,right,gravity,flip);
}

int main() {
    cin >> N >> M;
    
    //input and initialize
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            D[i][j][0] = INT_MAX;
            D[i][j][1] = INT_MAX;
            cin >> map[i][j];
            if(map[i][j] == 'C') {
                start = make_pair(i,j);
                D[i][j][1] = 0;
                q.push(make_pair(make_pair(i,j),true));
            } else if(map[i][j] == 'D') {
                goal = make_pair(i,j);
            }
        }
    }

    //build up first queue
    go_left(start.first,start.second,1,0);
    go_right(start.first,start.second,1,0);
    cout << "after build up..\n";
    printMap(); 
    while(!q.empty()) {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        int y = p.first.first;
        int x = p.first.second;
        int g = p.second;
        int flip = D[y][x][g];
        //cout << "target : " << y << " " << x << " " << g << " " << flip << "\n";
        //flip!
        flip++;
        g = !g;
        int new_y = y;
        if(g) {
            while(new_y < N-1 && map[new_y+1][x] != '#') new_y++;
            if(new_y >= N-1) continue; //cant flip
        } else {
            while(new_y > 0 && map[new_y-1][x] != '#') new_y--;
            if(new_y <= 0) continue; //cant flip 
        }
        //record and go!
        if(D[new_y][x][g] > flip) {
            D[new_y][x][g] = flip;
            go_left(new_y,x,g,flip);
            go_right(new_y,x,g,flip);
        }
        cout << "end of while\n";
        printMap();
        cout << "qsize : " << q.size() << "\n";
    }
    int ans = min(D[goal.first][goal.second][0],D[goal.first][goal.second][1]);
    if(ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}