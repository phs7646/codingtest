#include<iostream>
#include<vector>
#include<algorithm>

const long long MOD = 1000000007;

using namespace std;
long long powN(int N) {
    long long result = 1;
    long long base = 2;
    while (N > 0) {
        if (N % 2 == 1) {
            result = (result * base) % MOD;
        }
        N = N >> 1;
        base = (base * base) % MOD;
    }
    return result;
}
int main() {
    int N;
    cin >> N;
    long long answer = 0;
    vector<long long> scobil(N);
    for(int i = 0;i < N;i++) cin >> scobil[i];
    

    sort(scobil.begin(),scobil.end());

    if(N==1) {
        cout << 0;
        return 0;
    } else if(N==2) {
        cout << (MOD + scobil[1] - scobil[0])%MOD;
        return 0;
    }
    long long value = 0;
    long long value2 = 1;
    for(int dist = 1;dist <= (N-1)/2;dist++) {
        long long diff = (MOD + scobil[N-dist] - scobil[dist-1]) % MOD;
        if(diff < 0) exit(-1);
        value = (value + diff) % MOD;
        long long value3 = powN(N-dist-1);
        long long num_add = (value * ((value2 + value3) % MOD)) % MOD;
        answer = (answer + num_add)%MOD;
        value2 = (value2<<1) % MOD;
    }
    if(N%2 == 0) {
        int dist = N/2;
        long long diff = (MOD + scobil[N-dist] - scobil[dist-1]) % MOD;
        if(diff < 0) exit(-1);
        value = (value + diff) % MOD;
        long long num_add = (value * value2) % MOD;
        answer = (answer + num_add)%MOD;
    }
    cout << answer;
    return 0;
}