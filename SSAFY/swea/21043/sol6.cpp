#include<iostream>
#include<vector>
#include<algorithm>
const int mod = 1000000007;
using namespace std;

long long modAccum(long long n) {
    return (n * ((n+1)%mod) / 2 )% mod;
}
long long modMul(long long a, long long b) {
    //b는 mod되지 않은 row한 값이어야함.
    long long result = 0;
    while (b) {
        if (b % 2 == 1) {
            result = (result + a) % mod;
        }
        a = (2 * a) % mod;
        b /= 2;
    }
    return result;
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
        vector<int> w(D+1);
        for(int i = 0;i <= D;i++) cin >> w[i];
        int Q; cin >> Q;
        cout << '#' << t << " ";
        for(int q = 0;q < Q;q++) {
            int v; long long c;
            cin >> v >> c;
            long long answer = 0;
            //if(D < 2 * v)  answer = w[D] - c * w[D-v];
            //else answer = w[D] - c * w[D-v] + (c * (c+1))/2 * w[D-2*v];
            if(D < 2 * v) answer = modSub(w[D],modMul(w[D-v],c));
            else {
                long long t1 = w[D-v];
                long long t2 = w[D-2*v];
                long long it = t1 - t2;
                answer = w[D];
                for(int i = 0;i < c;i++) {
                    answer = modSub(answer,it);
                    it = modSub(it,t2);
                }
                //answer += sum(1..i) * t2;
                //long long count = c*(c+1)/2;
                //answer = modAdd(modSub(w[D],modMul(t1,c)),modMul(t2,count));
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}
// 식 다시 세우고 식의 각 단계에서 mod된 값과 그렇지 않은 값 확실하게 분리하기
// q안에 c짜리 반복문 들어가면 반드시 터짐

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

*/