#include<iostream>
#include<vector>
#include<random>
#include<cmath>
using namespace std;

random_device rd;

long long mulmod(long long x, long long y, long long p) {
    //(x * y) % p
    long long result = 0;
    x = x % p;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result + x) % p;
        }
        x = (x * 2) % p;
        y /= 2;
    }
    return result;
}
long long powmod(long long a, long long b, long long p) {
    // (a^b) % p
    long long result = 1;
    a = a % p;
    while (b > 0) {
        if (b % 2 == 1) {
            result = mulmod(result, a, p);
        }
        a = mulmod(a, a, p);
        b /= 2;
    }
    return result;
}


bool millerTest(long long d, long long n) {
    // 밀러라빈 테스트
    mt19937 gen(rd());
    uniform_int_distribution<long long> dis(2, n - 2);

    long long a = dis(gen);
    long long x = powmod(a, d, n);
    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = mulmod(x, x, n);
        d *= 2;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool _isPrime(long long n) {
    //밀러 라빈을 활용한 소수 판정
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    for (int i = 0; i < 1000; i++) {
        if (!millerTest(d, n)) return false;
    }
    return true;
}

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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

long long getFactor(long long n) {
    // Pollard's Rho 알고리즘
    mt19937_64 gen(rd());
    uniform_int_distribution<long long> dis(1, n-1);
    long long x = dis(gen);
    long long y = x;
    long long c = dis(gen);
    long long d = 1;
    auto f = [&](long long x) { return (mulmod(x, x, n) + c) % n; };
    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(abs(x - y), n);
    }
    return d;
}


vector<long long> getprimes(long long n) {
    //sqrt sqrt N 까지 소인수 분해 한 다음 남은 수는 (큰)두 소수의 곱이다
    vector<long long> ret;
    if (n < 2) return ret;
    long long sqrtn = 1000000;
    
    //sqrt sqrt N 까지의 소수 찾기
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
    if(n == 1) return ret;

    // 남은 수는 큰 두 소수의 곱이거나 소수 하나다
    if(_isPrime(n)) {
        ret.push_back(n);
    }
    else {
        long long t = mysqrt(n);
        if(t * t == n) ret.push_back(t);
        else {
            long long factor = getFactor(n);
            ret.push_back(factor);
            ret.push_back(n/factor);
        }
    }

    return ret;
}

int main() {
    long long N;
    cin >> N;
    vector<long long> primes = getprimes(N);
    int primesize = primes.size();
    //for(long long prime : primes) cout << prime << " ";
    //cout << "\n";
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