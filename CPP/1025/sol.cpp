#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N,M;
int answer = -1;
int answer_len = 0;

bool issquare(int num) {
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

vector<pair<int,int>> series(int y1, int x1, int y2, int x2) {
    vector<pair<int,int>> v;
    v.push_back({y1,x1});
    v.push_back({y2,x2});
    int yd = y2 - y1;
    int xd = x2 - x1;
    int currenty = y2 + yd;
    int currentx = x2 + xd;
    while(true) {
        if(currenty < 0 || currenty >= N) break;
        if(currentx < 0 || currentx >= M) break;
        v.push_back({currenty,currentx});
        currenty += yd;
        currentx += xd;
    }
    return v;
}

int main() {
    cin >> N >> M;
    vector<vector<int>> map(N,vector<int>(M,0));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            //cin >> map[i][j];
            if(answer < 0 && map[i][j] == 0) answer = 0;
            else if(answer < 1 && map[i][j] == 1) answer = 1;
            else if(answer < 4 && map[i][j] == 4) answer = 4;
            else if(answer < 9 && map[i][j] == 9) answer = 9;
        }
    }
    if(answer != 0) answer_len = 1;
    //pick first, pick second
    for(int y1 = 0;y1 < N;y1 ++) {
        for(int x1 = 0; x1 < M;x1++) {
            //first is y1,x1
            for(int y2 = 0;y2 < N;y2++) {
                for(int x2 = 0;x2 < M;x2++) {
                    //second is y2,x2
                    if(y1 == y2 && x1 == x2) continue;
                    vector<pair<int,int>> v = series(y1,x1,y2,x2);
                    if(v.size() < answer_len) continue;
                    int currentlen = answer_len;
                    int currentval = 0;
                    for(int i = 0;i < currentlen;i++) {
                        int y = v[i].first;
                        int x = v[i].second;
                        currentval = currentval*10 + map[y][x]; 
                    }
                    if(issquare(currentval) && answer < currentval) {
                        answer = currentval;
                        answer_len = static_cast<int>(log10(currentval)) + 1;;
                    }
                    while(currentlen < v.size()) {
                        
                        //append
                        int y = v[currentlen].first;
                        int x = v[currentlen].second;
                        currentval = currentval*10 + map[y][x];
                        currentlen++;
                        //check
                        if(issquare(currentval) && answer < currentval) {
                            answer = currentval;
                            answer_len = static_cast<int>(log10(currentval)) + 1;
                        }
                        
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}