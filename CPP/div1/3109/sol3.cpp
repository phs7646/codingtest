#include <iostream>
#include <vector>
using namespace std;

int R,C;
int ans = 0;


int findnext(int r, int c,const vector<vector<bool>>& map) {
    int current = r+1;
    while(current < R && map[current][c]) current++;
    return current;
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
    vector<int> current(C,0);
    while(true) {
        //find minimum available pipe
        bool flag = true;
        while(flag) {
            flag = false;
            for(int c = 0;c < C;c++) {
                //if current[c] is invalid or low, find next
                if(map[current[c]][c] || (c-1 >= 0 && current[c-1] - 1 > current[c]) || (c+1 < C && current[c+1] -  1 > current[c])) {
                    flag = true;
                    current[c] = findnext(current[c],c,map);
                    if(current[c] >= R) {
                        cout << ans;
                        return 0;
                    }
                }
            }
        }
        ans++;

        for(int c = 0; c < C;c++) {
            current[c] = findnext(current[c],c,map);
            if(current[c] == R) {
                cout << ans;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}