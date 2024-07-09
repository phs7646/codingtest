#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> points;
vector<vector<int>> map(9,vector<int>(9));

bool solve(int pos) {
    if(pos == points.size()) return true;
    int x = points[pos].first;
    int y = points[pos].second;
    //find candidate for points[pos]
    vector<bool> cand(10,true);
    
    //line
    for(int i = 0;i < 9;i++) {
        cand[map[x][i]] = false;
        cand[map[i][y]] = false;
    }

    //square
    int sqaurex = x/3;
    int squarey = y/3;
    for(int i = sqaurex * 3; i < sqaurex * 3 + 3; i++) {
        for(int j = squarey * 3; j < squarey * 3 + 3;j++) {
            cand[map[i][j]] = false;
        }
    }


    for(int i = 1;i <= 9;i++) {
        if(!cand[i]) continue;
        map[x][y] = i;
        if(solve(pos+1)) return true;
    }

    map[x][y] = 0;
    return false;
}

int main() {
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            if(map[i][j] == 0) points.push_back({i,j});
        }
    }
    solve(0);
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) cout << map[i][j];
        cout<<"\n";
    }

    return 0;
}