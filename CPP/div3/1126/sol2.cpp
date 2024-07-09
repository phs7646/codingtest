#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxima = 500000;
int dp[500001][2];

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for (int i = 0; i < N; ++i) {
        int h = heights[i];
        for (int diff = 0; diff <= maxima; ++diff) {
            if (dp[diff][0] != 0 || diff == 0) {
                // 높은 쪽에 더 쌓기
                dp[diff + h][1] = max(dp[diff + h][1], dp[diff][0] + h);
                // 낮은 쪽에 더 쌓기
                if (diff >= h) {
                    dp[diff - h][1] = max(dp[diff - h][1], dp[diff][0] + h);
                } else {
                    dp[h - diff][1] = max(dp[h - diff][1], dp[diff][0] + h);
                }
            }
        }
        for (int diff = 0; diff <= maxima; ++diff) {
            dp[diff][0] = dp[diff][1];
        }
    }

    if (dp[0][0] > 0) {
        cout << dp[0][0] / 2 << endl;  // 두 탑의 높이가 같을 때의 한 탑의 높이 출력
    } else {
        cout << -1 << endl;  // 불가능할 때
    }

    return 0;
}
