#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void printAnswer(long long a,long long b) {
    //a/b를 기약분수 꼴로 프린트
    long long g = gcd(a,b);
    a /= g;
    b /= g;
    cout << a << "/" << b;
}

int main() {
    //input, rem 구하기
    long long N; cin >> N;
    vector<string> in(N);
    for(long long i = 0;i < N;i++) cin >> in[i];
    long long K;cin >> K;
    vector<long long> rem(N);
    for(long long i = 0;i < N;i++) {
        long long r = 0;
        for(long long index = 0;index < in[i].size();index++) {
            r = r * 10 + (in[i][index]-'0');
            r %= K;
        }
        rem[i] = r;
    }
    // cout << "rem : ";
    // for(int r : rem) cout << r << " ";
    // cout << endl;
    long long max_bit = 1 << N;
    vector<vector<long long>> dp(max_bit,vector<long long>(K,0)); //dp[bit][k] = bit를 가지고 만드는 수 중 rem이 k인 수
    //length 1 initialize
    for(long long i = 0;i < N;i++) {
        long long bit = 1 << i;
        dp[bit][rem[i]] = 1;
    }
    //dp start
    for(long long length = 1;length < N;length++) {
        //bit의 len 이 length인 애들을 다음dp에 누적시키기
        for(long long bit = 0;bit < max_bit;bit++) {
            //bit의 len 조사
            long long total_len = 0;
            long long num = 0;
            for(long long i = 0;i < N;i++) {
                if(bit & (1<<i)) {
                    num++;
                    total_len += in[i].size();
                }
            }
            if(num != length) continue;
            for(long long i = 0;i < N;i++) {
                if(bit & (1<<i)) continue;
                long long new_bit = bit | (1<<i);
                //비트 뒤에 i를 추가한다면 추가되는 add_rem 계산
                long long add_rem = rem[i];
                for(long long k = 0;k < total_len;k++) {
                    add_rem *= 10;
                    add_rem %= K;
                }
                for(long long j = 0;j < K;j++) {
                    //dp[bit][j] -> dp[new_bit][j+add_rem]
                    dp[new_bit][(j+add_rem)%K] += dp[bit][j];
                }
            }
        }
    }
    long long total = 0;
    for(int k = 0;k < K;k++) total += dp[max_bit-1][k];
    // for(int n : dp[max_bit-1]) cout << n << " ";
    // cout << endl;
    // cout << dp[max_bit-1][0] << "/" << total;
    if(dp[max_bit-1][0] == 0) {
        cout << "0/1";
    } else if(dp[max_bit-1][0] == total) {
        cout << "1/1";
    } else {
        printAnswer(dp[max_bit-1][0],total);
    }
    return 0;
}