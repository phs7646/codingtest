#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int N = s1.length(),M = s2.length();
    vector<vector<int>> dp(N+1,vector<int>(M+1,0));

    for(int i = 1;i <= N;i++) {
        dp[i][0] = 0;
        for(int j = 1;j <= M;j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout << dp[N][M] << "\n";

    if(dp[N][M] > 0) {
        string answer;
        int i = N-1;
        int j = M-1;
        while(i >= 0 && j >= 0) {
            if(s1[i] == s2[j]) {
                answer.push_back(s1[i]);
                i--;
                j--;
            } else if(dp[i][j+1] < dp[i+1][j]) {
                //s1[i] 는 포함되는 수임!
                j--;
            } else i--;
        }
        reverse(answer.begin(),answer.end());
        cout << answer;
    }
    return 0;
}