#include<iostream>
#include<vector>
#include<algorithm>
const int mod = 1000000007;
using namespace std;

long long inv[2001];

long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long modInv(long long n) {
    return modPow(n, mod - 2);
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
    for(int i = 2;i <= 2000;i++) {
        inv[i] = modInv(i);
    }
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
            long long it = c;
            for(int i = 2;i <=k;i++) {
                it = modMul(it,c+i-1);
                it = modMul(it,inv[i]);
                if(i%2==0) answer = modAdd(answer,modMul(it,w[D-i*v]));
                else answer = modSub(answer,modMul(it,w[D-i*v]));
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}