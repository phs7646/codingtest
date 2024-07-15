#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;

int A, B;

long long solve(int N) {
    vector<long long> dp(N + 1, LLONG_MAX);
    for (int i = A; i <= min(B, N); ++i) {
        dp[i] = 0;
    }
    for (int mass = A; mass <= N; ++mass) {
        if (dp[mass] == LLONG_MAX) continue;
        
        for (int detach = A; detach <= B; ++detach) {
            int remain = mass + detach;
            if (remain > N) break;
            dp[remain] = min(dp[remain], dp[mass] + (long long)mass * detach);
        }
    }

    return dp[N] == LLONG_MAX ? -1 : dp[N];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N >> A >> B;
        cout << '#' << t << " " << solve(N) << "\n";
    }

    return 0;
}
