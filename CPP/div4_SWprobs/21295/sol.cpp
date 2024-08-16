#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef __int128 ll;

ll _pow(ll N,int K) {
    if(K == 1) return N;
    if(K == 2) return N*N;
    if(K == 3) return N*N*N;
    ll n = N*N;
    return n*n;
}

ll Sum(ll N,int K) {
    
    if(K == 1) {
        ll div = 2;
        return N * (N+1) / div;
    } else if(K == 2) {
        ll div = 6;
        return N * (N + 1) * (2 * N + 1) / div;
    } else if(K == 3) {
        ll s = Sum(N,1);
        return s * s;
    } else {
        ll div = 30;
        return N * (N + 1) * (2 * N + 1) * (3 * N * N + 3 * N - 1) / div;
    }
}


string int128ToString(ll num) {
    if (num == 0) return "0";
    string result;
    bool negative = false;
    while (num > 0) {
        result.insert(result.begin(), '0' + num % 10);
        num /= 10;
    }
    return result;
}

bool answer[1000001];
bool answer2[1000001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T;cin >> T;
    for(int t = 1;t <= T;t++) {
        memset(answer,0,sizeof(answer));
        memset(answer2,0,sizeof(answer));
        int N;cin >> N;
        int K; cin >> K;

        //0 : 큰쪽에 속함
        //1 : 작은쪽에 속함
        //N을 큰쪽에 속하게 한다.
        ll diff1 = Sum(N,K);
        for(ll i = N-1;i >= 1;i--) {
            //2 * i^K 이 diff보다 작다면 넘긴다
            ll c = _pow(i,K);
            c = c + c;
            if(diff1 >= c) {
                answer[i] = true;
                diff1 -= c;
            }
        }
        //diff1 에 해당 값이 저장됨
        
        //N을 작은쪽에 속하게 한다.
        ll diff2 = Sum(N,K);
        for(ll i = N;i >= 1;i--) {
            //2 * i^K 이 diff보다 작다면 넘긴다
            ll c = _pow(i,K);
            c = c + c;
            if(diff2 >= c) {
                answer2[i] = true;
                diff2 -= c;
            }
        }
        //diff2 에 해당 값이 저장됨
        if(diff1 <= diff2) {
            cout << int128ToString(diff1) << ' ';
            for(int i = 1;i <= N;i++) {
                if(answer[i]) cout << '1';
                else cout << '0';
            }
        } else {
            cout << int128ToString(diff2) << ' ';
            for(int i = 1;i <= N;i++) {
                if(answer2[i]) cout << '1';
                else cout << '0';
            }
        }
        
        cout << '\n';
    }

    return 0;
}