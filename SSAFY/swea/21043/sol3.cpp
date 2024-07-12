#include<iostream>
#include<vector>
#include<algorithm>
const int mod = 1000000007;
using namespace std;

long long modAccum(long long n) {
    return (n * (n+1) / 2 )% mod;
}
long long modMul(long long b, long long a) {
    //a는 mod되지 않은 row한 값이어야함.
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
        long long D; cin >> D;
        vector<long long> w(D+1);
        for(int i = 0;i <= D;i++) cin >> w[i];
        int Q; cin >> Q;
        cout << '#' << t;
        for(int q = 0;q < Q;q++) {
            long long v; long long c;
            cin >> v >> c;
            long long answer = 0;
            //if(D < 2 * v)  answer = w[D] - c * w[D-v];
            //else answer = w[D] - c * w[D-v] + (c * (c+1))/2 * w[D-2*v];
            if(D < 2 * v) answer = modSub(w[D],modMul(c,w[D-v]));
            else answer = modAdd(modSub(w[D],modMul(c,w[D-v])),modMul(modAccum(c),w[D-2*v]));
            cout << " " << answer;
        }
        cout << "\n";
    }
    return 0;
}