#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/* codes */

int main() {
    int N;
    cin >> N;
    vector<vector<int>> map(N,vector<int>(N));
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) cin >> map[i][j];
    vector<vector<long long>> count(N,vector<long long>(N));
    count[0][0] = 1;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            int num = map[i][j];
            if(num == 0) continue;
            if(j+num < N) count[i][j+num] += count[i][j];
            if(i+num < N) count[i+num][j] += count[i][j];
        }
    }
    
    cout << count[N-1][N-1];
    return 0;
}