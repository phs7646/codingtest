#include<iostream>
#include<vector>
#include<algorithm>
const int mod = 1000000007;
using namespace std;

long long inv[2001];

long long modInv(long long n) {
    long long result = 1;
    long long exp = mod-2;
    long long base = n;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
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
    for(int i = 2;i <= 1999;i++) {
        inv[i] = modInv(i);
    }
    int w[2000];
    int T;cin >> T;
    for(int t = 1;t <= T;t++) {
        int D; cin >> D;
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
                long long t = modMul(it,w[D-i*v]);
                if(i%2==0) answer = modAdd(answer,t);
                else answer = modSub(answer,t);
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}