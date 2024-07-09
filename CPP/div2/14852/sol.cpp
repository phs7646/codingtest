#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long MOD = 1000000007;
    if(N == 1) {
        cout << 2;
        return 0;
    }
    vector<vector<long long>> dp(N,vector<long long>(2)); //0:둘다,1:한쪽만
    dp[0][0] = 2;
    dp[0][1] = 1;
    dp[1][0] = 7;
    dp[1][1] = 3;
    for(int i = 2;i < N;i++) {
        dp[i][1] = (dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][0] = ((2*dp[i][1])%MOD + dp[i-2][0])%MOD;
    }
    cout << dp[N-1][0];
    return 0;
}