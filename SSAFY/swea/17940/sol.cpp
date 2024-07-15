#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    long long dp[109];
    for(int t = 1;t <= T;t++) {
        int N,A,B;
        cin >> N >> A >> B;
        for(int i = 0;i < A;i++) dp[i] = -1;
        for(int i = A;i <= B;i++) dp[i] = 0;
        for(int i = B+1;i <= N;i++) dp[i] = -1;
        //B+1부터 N까지의 dp를 계산
        for(int i = B+1;i <= N;i++) {
            //i를 처리하려면 A를 떼는 것 부터 B를 떼는 것 까지
            long long answer = LLONG_MAX;
            for(long long detach = A;detach <= B;detach++) {
                //detach, i-detach
                if(dp[detach] == -1 || dp[i-detach] == -1) continue; //불가능
                long long cost = detach * (i-detach) + dp[detach] + dp[i-detach];
                answer = min(answer,cost);
            }
            if(answer == LLONG_MAX) dp[i] = -1;
            else dp[i] = answer;
        }
        cout << '#' << t << " " << dp[N] << "\n";
        
    }

    return 0;
}