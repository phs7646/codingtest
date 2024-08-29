#include<iostream>
#include<bitset>
#include<string>
#include<vector>
using namespace std;

#define MOD 9901
int N,M;
int origin_bit;
int cur_bit;
int dp[14][1<<14];
vector<int> horimask;

string intToStr(int bit) {
    bitset<32> binary(bit);
    return binary.to_string().substr(32-M,M);
}
void printDP(int n) {
    for(int bit = 0;bit < (1<<M);bit++) {
        cout << intToStr(bit) << " " << dp[n][bit] << endl;
    }
}
int flipBit(int bit) {
    return (~bit) & ((1<<M)-1);
}

void initDP0(int pos) {
    if(pos == M) {
        dp[0][cur_bit]++;
        horimask.emplace_back(cur_bit);
    }
    else {
        initDP0(pos+1);
        if(pos < M-1) {
            int backup = cur_bit;
            cur_bit |= (1<<pos);
            cur_bit |= (1<<(1+pos));
            initDP0(pos+2);
            cur_bit = backup;
        }
    }
}

int main() {
    cin >> N >> M;
    //dp[0] build
    initDP0(0);
    int max_bit = 1<<M;

    for(int n = 0;n < N-1;n++) { //maximum 13
        //n -> n+1 update
        for(int bit = 0;bit < max_bit;bit++) { //maximum : 2^14
            if(dp[n][bit] == 0) continue;
            dp[n][bit] %= MOD;
            int targetbit = flipBit(bit);
            for(int mask : horimask) { //maximum : 610 case (when M=14)
                if(!(targetbit & mask)) {
                    dp[n+1][targetbit | mask] += dp[n][bit];
                }
            }
        }
    }

    // O( 13 * 2^14 * 610)  ~~ 1.3억....
    cout << dp[N-1][max_bit-1] % MOD;
    return 0;
}