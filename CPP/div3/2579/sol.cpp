#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++) cin >> A[i];
    if(N==1) {
        cout << A[0];
        return 0;
    }
    vector<vector<int>> dp(N,vector<int>(2));
    dp[0][0] = A[0];
    dp[0][1] = A[0];
    dp[1][0] = A[1];
    dp[1][1] = A[0] + A[1];
    
    for(int i = 2;i < N;i++) {
        dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + A[i];
        dp[i][1] = dp[i-1][0] + A[i];
    }
    cout << max(dp[N-1][0],dp[N-1][1]);
    return 0;
}