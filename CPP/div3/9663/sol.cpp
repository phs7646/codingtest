#include<iostream>

using namespace std;

int N;
long answer;
int map[15][15];

void dfs(int depth) {
    if(depth==N) {
        answer++;
        return;
    }
    for(int j = 0;j < N;j++) {
        if(map[depth][j]) continue;
        for(int d = 1;depth+d < N;d++) {
            map[depth+d][j]++; //같은 열
	        if(j-d >= 0) map[depth+d][j-d]++; //왼쪽 아래 대각선
	        if(j+d < N) map[depth+d][j+d]++; //오른쪽 아래 대각선
        }
        dfs(depth+1);
        for(int d = 1;depth+d < N;d++) {
            map[depth+d][j]--; //같은 열
	        if(j-d >= 0) map[depth+d][j-d]--; //왼쪽 아래 대각선
	        if(j+d < N) map[depth+d][j+d]--; //오른쪽 아래 대각선
        }
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << answer;
    return 0;
}