#include <iostream>

using namespace std;



long long modadd(long long a,long long b, long long mod) {
    a %= mod;
    b %= mod;
    return (a+b) % mod; //a+b is in long long range
}

long long modmul(long long a,long long b, long long mod) {
    long long result = 0;  
    a %= mod;
    b %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = modadd(result,a,mod);
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return result;
}

long long modpow(long long a,long long n, long long mod) {
    long long result = 1;
    a %= mod;
    while(n > 0) {
        if(n % 2 == 1) {
            result = modmul(a, result, mod);  
        }
        a = modmul(a,a,mod);
        n /= 2;
    }
    return result;
}

long long modsubone(long long a,long long mod) {
    if(a == 0) return mod-1;
    else return a-1;
}

long long modsum(long long a,long long n,long long mod) {
    a %= mod;
    if(n == 0) return 0;
    if(n == 1) return 1;
    //(1 + a^1 + ... a^n-1)
    long long result = 0;
    if(n % 2 == 1) {
        result = modpow(a,n-1,mod);
    }
    long long S_halfn = modsum(a,n/2,mod);
    long long a_halfn = modpow(a,n/2,mod);
    result = modadd(result, modadd(S_halfn,modmul(a_halfn,S_halfn,mod),mod) ,mod);
    return result;
}

int main() {

    long long m,a,c,X0,n,g;

    cin >> m >> a >> c >> X0 >> n >> g;

    if(a == 0) {
        //c mod n
        cout << (c%m)%g;
        return 0;
    } else if (a == 1) {
        //X0 + nc
        cout << (modadd(X0,modmul(n,c,m),m))%g;
        return 0;
    }

    long long a_n = modpow(a,n,m);
    long long S_n = modsum(a,n,m);; //(1 + a^1 + a^2 + ... a^n-1)

    //cout << S_n << "\n";

    long long X_n = modadd(modmul(a_n,X0,m),modmul(S_n,c,m),m);
    
    cout << X_n%g;

    return 0;
}