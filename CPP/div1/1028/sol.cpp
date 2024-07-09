#include <iostream>
#include <vector>

using namespace std;

int R,C;

int answer = -1;

int maxlength(int i,int j) {
    //min among j, C-j-1, (R-i-1)/2
    int len = j;
    if(C-j-1 < len) len = C-j-1;
    int down = (R-i-1)/2;
    if(down < len) len = down;
    return len;
}

int main() {
    cin >> R >> C;

    vector<vector<int>> map(R, vector<int>(C,0));
    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            if(answer == -1 && map[i][j] == 1) answer = 0;
        }
    }
    if(answer == -1) {
        cout << 0;
        return 0;
    }

    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            //current top = i,j
            if(map[i][j] == 0) continue;
            //if maximum possible is less than answer, continue
            int possible = maxlength(i,j);
            if(possible <= answer) continue;

            //find max length for upper triangle
            int dist = 0;
            while(dist < possible) {
                //find if dist+1 is possible
                dist++;
                if(map[i+dist][j-dist] == 0 || map[i+dist][j+dist] == 0) {
                    dist--;
                    break;
                }
            }

            //if maximum upper length is less than answer, continue
            if(dist <= answer) continue;

            //find max diamond
            while(dist > answer) {
                bool flag = true;
                for(int k = 1;k < dist;k++) {
                    if(map[i+dist+k][j-dist+k] == 0 || map[i+dist+k][j+dist-k] == 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag && map[i+dist+dist][j]) {
                    answer = dist;
                    break;
                }
                dist--;
            }
        }
    }
    cout << answer+1;
    return 0;
}