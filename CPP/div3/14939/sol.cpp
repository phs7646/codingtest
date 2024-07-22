#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

pair<int,int> moves[] = {{0,0},{0,1},{1,0},{-1,0},{0,-1}};
bool origin[10][10];
bool v[10][10];
void press(int i,int j) {
    for(int m = 0;m < 5;m++) {
        int y = i + moves[m].first;
        int x = j + moves[m].second;
        if(0 <= y && y < 10 && 0 <= x && x < 10) {
            v[y][x] = !v[y][x];
        }
    }
}

int main() {
    for(int i = 0;i < 10;i++) {
        string s; cin >> s;
        for(int j = 0;j < 10;j++) {
            origin[i][j] = s[j] == '#' ? false : true;
        }
    }
    int answer = 101;
    int max_bit = 1<<10;
    for(int bit = 0;bit < max_bit;bit++) {
        int num = 0;
        //restore origin
        for(int i = 0;i < 10;i++) for(int j = 0;j < 10;j++) v[i][j] = origin[i][j];
        //첫번째 줄을 bit로 
        for(int j = 0;j < 10;j++) {
            if(bit & (1<<j)) {
                press(0,j);
                num++;
            }
        }
        //이제 첫번째줄에 영향을 미치는 건 바로 아랫칸 누르기 밖에 없음.(그리디)
        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 10;j++) {
                if(v[i][j]) {
                    //i+1,j를 눌러야함.
                    press(i+1,j);
                    num++;
                }
            }
        }
        //마지막줄은 모두 꺼져있어야함
        bool success = true;
        for(int j = 0;j < 10;j++) {
            if(v[9][j]) {
                success = false;
                break;
            }
        }
        if(success) answer = min(answer,num);
    }
    cout << answer;
    return 0;
}