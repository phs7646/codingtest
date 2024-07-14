#include<iostream>
#include<vector>
#include<algorithm>
const int mod = 1000000007;
using namespace std;
long long func1(int n) {
    return (n * (n + 1) / 2)%mod;
}

long long func2(int n) {
    return (n * (n + 1) * (n + 2) / 6)%mod;
}

std::vector<long long> computeFuncs(int k, int n) {
    std::vector<long long> results;
    results.push_back(func1(n));
    if (k == 1) return results;

    results.push_back(func2(n));
    if (k == 2) return results;

    std::vector<long long> previous = results;
    for (int j = 3; j <= k; ++j) {
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += previous[i - 1];
            previous.push_back(sum);
        }
        results.push_back(sum);
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
            long long answer = modSub(w[D],modMul(c,w[D-v]));
            int k = D/v;
            vector<long long> values = computeFuncs(k,c);
            for(int i = 2;i <= k;i++) {
                if(i % 2 == 1) {
                    answer = modSub(answer,modMul(values[i-2],w[D-i*v]));
                } else {
                    answer = modAdd(answer,modMul(values[i-2],w[D-i*v]));
                }
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}
// func 이상함 다시짜야함
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