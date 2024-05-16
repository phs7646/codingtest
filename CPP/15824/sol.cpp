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
    vector<unsigned int> scobil(N);
    for(int i = 0;i < N;i++) cin >> scobil[i];
    sort(scobil.begin(),scobil.end());
    int left = 0;
    while(left < N-1) {
        long long num = 1;
        int right = left+1;
        while(right < N) {
            long long diff = (scobil[right] - scobil[left]) % MOD;
            answer = (answer + ((diff * num)%MOD)) % MOD;
            num = (num<<1) % MOD;
            right++;
        }
        left++;
    }

    cout << answer;
    return 0;
}