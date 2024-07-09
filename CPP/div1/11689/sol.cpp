#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long mysqrt(long long x) {
    if (x == 0 || x == 1) return x;

    long long start = 1, end = x, ans = 0;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (mid <= x / mid) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

vector<long long> getprimes(long long n) {
    vector<long long> ret;
    if (n < 2) return ret;
    long long sqrtn = mysqrt(n);
    
    vector<bool> isPrime(sqrtn+ 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (long long i = 2; i * i <= sqrtn; i++) {
        if (isPrime[i]) { 
            for (long long j = i * i; j <= sqrtn; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // 소수들 중 n의 인수인 것만 벡터에 추가
    for (long long i = 2; i <= sqrtn; i++) {
        if (isPrime[i] && n%i == 0) {
            ret.push_back(i);
            while(n%i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1)ret.push_back(n);
    return ret;
}

int main() {
    long long N;
    cin >> N;
    if(N==1) {
        cout << 1;
        return 0;
    }
    vector<long long> primes = getprimes(N);
    int primesize = primes.size();
    int max_bit = 1 << primesize;
    long long count = N;
    for(int bit = 1;bit < max_bit;bit++) {
        int num_used = 0;
        long long num = 1;
        for(int i = 0;i < primesize;i++) {
            if(bit & (1<<i)) {
                num_used++;
                num = num * primes[i];
            }
        }
        if(num_used % 2 == 1) count -= N/num;
        else count += N/num;
    }
    cout << count;
    return 0;
}
