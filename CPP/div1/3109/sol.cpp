#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int R,C;
stack<pair<int,int>> s;
int count = 0;

bool occupiable(pair<int,int> coor, const vector<vector<bool>>& map) {
    int r = coor.first;
    int c = coor.second;
    if(0 > r || r >= R || 0 > c || c >= C) return false;
    if(map[r][c]) return false;
    return true;
}

bool backtrack(int r,int c, const vector<vector<bool>>& map) {
    //cout << "Backtrack " << r << "," << c << "\n";
    //r,c is already occupied
    //exam c+1 occupiable and forward
    if(c == C-1) return true;
    pair<int,int> next = {r-1,c+1};
    if(occupiable(next,map)) {
        s.push(next);
        if(backtrack(next.first,next.second,map)) return true;
        s.pop();
    }
    next.first++;
    if(occupiable(next,map)) {
        s.push(next);
        if(backtrack(next.first,next.second,map)) return true;
        s.pop();
    }
    next.first++;
    if(occupiable(next,map)) {
        s.push(next);
        if(backtrack(next.first,next.second,map)) return true;
        s.pop();
    }
    return false;
}

int main() {
    cin >> R >> C;
    vector<vector<bool>> map(R, vector<bool>(C, false));
    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            char c;
            cin >> c;
            if(c == 'x') map[i][j] = true;
        }
    }
    int count = 0;
    for(int t = 0;t < R;t++) {
        if(backtrack(t,0,map)) {
            count++;
            while(!s.empty()) {
                pair<int,int> coor = s.top();
                s.pop();
                map[coor.first][coor.second] = true;
            }
        }
    }

    cout << count;
    return 0;
}