#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int max_mask = 1<<N;
    vector<vector<int>> cost(N,vector<int>(N));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dp(max_mask,vector<int>(N,18000000)); //mask,i
    dp[1][0] = 0;

    for(int mask = 1; mask < max_mask; mask++) {
        for(int i = 0;i < N;i++) {
            if(!(mask & (1<<i))) continue;
            for(int j = 0;j < N;j++) {
                if(cost[i][j] != 0 && !(mask & (1<<j))) {
                    int new_mask = mask | (1<<j);
                    dp[new_mask][j] = min(dp[new_mask][j],dp[mask][i] + cost[i][j]);
                }
            }
        }
    }

    int answer = INT_MAX;
    for(int i = 1;i < N;i++) {
        if(cost[i][0] == 0) continue;
        answer = min(answer,dp[max_mask-1][i] + cost[i][0]);
    }

    cout << answer;
    return 0;
}