#include<iostream>
#include<vector>
#include<algorithm>
const int mod = 1000000007;
using namespace std;
vector<long long> calculateFuncValues(int k, int n) {
    // DP table 초기화
    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(n + 1, 0));

    // func(0, n) = n 초기화
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = i;
    }

    // func(1, n) 계산 및 DP table의 첫 번째 레벨에 저장
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = (dp[1][i - 1] + i) % mod;
    }

    // DP table을 채우기
    for (int level = 2; level <= k; ++level) {
        for (int i = 1; i <= n; ++i) {
            dp[level][i] = (dp[level][i - 1] + dp[level - 1][i]) % mod;
        }
    }

    // 각 레벨의 결과 추출
    std::vector<long long> results;
    for (int level = 0; level <= k; ++level) {
        results.push_back(dp[level][n]);
    }

    return results;
}
long long modAccum(long long n) {
    return (n * ((n+1)%mod) / 2 )% mod;
}
long long modMul(long long a, long long b) {
    return a*b % mod;
}
long long modAdd(long long a,long long b) {
    return (a + b) % mod;
}
long long modSub(long long a,long long b) {
    return (a+mod-b) % mod;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T;cin >> T;
    for(int t = 1;t <= T;t++) {
        int D; cin >> D;
        vector<long long> w(D+1);
        for(int i = 0;i <= D;i++) cin >> w[i];
        int Q; cin >> Q;
        cout << '#' << t << " ";
        for(int q = 0;q < Q;q++) {
            long long v; long long c;
            cin >> v >> c;
            long long answer = 0;
            int k = (D/v)-1;
            vector<long long> values = calculateFuncValues(k,c);
            for(int i = 0;i <= k;i++) {
                if(i % 2 == 0) {
                    answer = modSub(answer,modMul(values[i],w[D-(k+1)*c]));
                } else {
                    answer = modAdd(answer,modMul(values[i],w[D-(k+1)*c]));
                }
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}
// 식 다시 세우고 식의 각 단계에서 mod된 값과 그렇지 않은 값 확실하게 분리하기

/*
1~D원인 동전들 ...
N개 있다고 하면
v[i]에 대해
dp = dp + (dp+v[i]) ... => dp

dp_new[n] += dp[n-v[i]] + dp[n]
ex) 1 1 1 1
dp : 
1 0 0 0 0
1 1 0 0 0
1 2 1 0 0
1 3 3 1 0
1 4 6 4 1

answer = w[2] - w[1] - w[0]

1 1 0 0 0
1 2 1 0 0
1 3 3 1 0 ... 이런식으로 build된다
1 4 6 4 1
여기서 1원 동전 2개가 빠지면

dp_new[n] += dp[n-v[i]] + dp[n]
dp[n] -= dp[n-1] 해줘야함
1 3 3 1 0
1 4 6 4 1
1 3 3 1 0

build는 오른쪽부터
뺄 때는 왼쪽부터

v[a] -= c * v[0]
v[a+1] = 
v[a+1] -= c * v[1]
a부터 2a까지는 이렇게 빠짐	 
2a는?
최초에
v[2a] -= v[a]가 일어남 이 당시 a 는 v[a] - v[0]
다음에
v[2a] -= v[a]가 일어남 이 때 a 는 v[a] - 2v[0]
다음에
v[2a] -= v[a]가 일어남 이 때 a 는 v[a] - 3v[0]
따라서
v[2a] -= c *v'[a] + (c)(c+1)/2 * v[0]

v[2a+1]은?
v[2a+1] -= v[a+1]이 일어남 이때 v[a+1] = v'[a+1]-v[1] 
v[2a+1] -= v[a+1]이 일어남 이때 v[a+1] = v'[a+1]-2v[1] 
v[2a+1] -= v[a+1]이 일어남 이때 v[a+1] = v'[a+1]-3v[1] 
v[2a+1] -= v[a+1]이 일어남 이때 v[a+1] = v'[a+1]-4v[1]
따라서
v[2a+1] = v'[2a+1] - c*v'[a+1] + 1..c * v'[1] 



answer = w[D] - c*w[D-a] + sum(c)*w[D-2a] -sum(sum(c))*w[D-3a] ....

Task : 중첩된 sum을 어떻게 빨리 구할것인가
*/