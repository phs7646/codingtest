#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    
    vector<int> m(N);
    vector<int> c(N);
    for(int i = 0;i < N;i++) {
        cin >> m[i];
        if(m[i] > M) m[i] = M;
    }
    for(int i = 0;i < N;i++) cin >> c[i];

    int sum_cost = 0;
    for(int cost : c) sum_cost += cost; 
    vector<int> dp(M+1,sum_cost+1); //dp[i] : 현재 단계에서 메모리 i를 만드는 최소비용
    dp[0] = 0;

    for(int i = 0;i < N;i++) {
        for(int j = M; j >= m[i];j--) {
            dp[j] = min(dp[j], dp[j-m[i]] + c[i]);
        }
        for(int j = m[i]-1; j >= 1;j--) {
            dp[j] = min(dp[j],c[i]);
        }
    }

    cout << dp[M];

    return 0;
}