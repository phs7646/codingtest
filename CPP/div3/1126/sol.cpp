#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int maxima = 500000;
int dp[500001][2];

int main() {
    int N;
    cin >> N;
    int k; cin >> k;
    dp[k][0] = k;
    dp[k][1] = k;
    for(int i = 1;i < N;i++) {
        int h;
        cin >> h;
        for(int diff = 0;diff <= maxima;diff++) {
            if(dp[diff][0] != 0) {
                //dp[j][0] 에 최댓값이 담겨있다 diff, max
                //높은곳에 더 쌓기
                dp[diff+h][1] = max(dp[diff+h][1],dp[diff][0] + h);
                //낮은곳에 더 쌓기
                if(diff >= h) {
                    dp[diff-h][1] = max(dp[diff-h][1],dp[diff][0]); 
                } else {
                    int new_diff = h-diff;
                    int new_max = dp[diff][0] + new_diff;
                    dp[new_diff][1] = max(dp[new_diff][1],new_max);
                }
            }
        }
        for(int diff = 0;diff <= maxima;diff++) {
            dp[diff][0] = dp[diff][1];
        }
        //for(int i = 0;i < 20;i++) cout << dp[i][0] << " ";
        //cout << endl;
    }
    if(dp[0][0] > 0) cout << dp[0][0];
    else cout << -1;

    return 0;
}