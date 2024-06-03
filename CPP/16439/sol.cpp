#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> prefer(N,vector<int>(M));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) cin >> prefer[i][j];
    }
    int answer = 0;
    for(int i = 0;i < M-2;i++) {
        for(int j = i;j < M-1;j++) {
            for(int k = j;k < M;k++) {
                int value = 0;
                for(int n = 0;n < N;n++) {
                    value += max(max(prefer[n][i],prefer[n][j]),prefer[n][k]);
                }
                answer = max(answer,value);
            }
        }
    }
    cout << answer;
    return 0;
}