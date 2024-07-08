#include<iostream>
#include<vector>

#define bignum 1000007

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> v(N,vector<int>(3));
    for(int i = 0;i < N;i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    int answer = bignum;
    vector<vector<int>> dp(N,vector<int>(3,bignum)); //dp[i][k] : i번째 집을 k로칠할 때
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    //0번집을 0으로 칠함
    dp[1][0] = bignum;
    dp[1][1] = dp[0][0] + v[1][1];
    dp[1][2] = dp[0][0] + v[1][2];
    for(int i = 2;i < N;i++) {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + v[i][0];
        dp[i][1] = min(dp[i-1][2],dp[i-1][0]) + v[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + v[i][2];
    }
    answer = min(answer,min(dp[N-1][1],dp[N-1][2]));
    //0번집을 1으로 칠함
    dp[1][0] = dp[0][1] + v[1][0];
    dp[1][1] = bignum;
    dp[1][2] = dp[0][1] + v[1][2];
    for(int i = 2;i < N;i++) {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + v[i][0];
        dp[i][1] = min(dp[i-1][2],dp[i-1][0]) + v[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + v[i][2];
    }
    answer = min(answer,min(dp[N-1][0],dp[N-1][2]));
    //0번집을 2으로 칠함
    dp[1][0] = dp[0][2] + v[1][0];
    dp[1][1] = dp[0][2] + v[1][1];
    dp[1][2] = bignum;
    for(int i = 2;i < N;i++) {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + v[i][0];
        dp[i][1] = min(dp[i-1][2],dp[i-1][0]) + v[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + v[i][2];
    }
    answer = min(answer,min(dp[N-1][0],dp[N-1][1]));
    cout << answer;
    return 0;
}