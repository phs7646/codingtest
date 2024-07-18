#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long N;
int K;
long long dp[19][1024];
int numUsed[1024];
//dp [l][bit] : 길이 l에 bit상태를 가진 수의 갯수

int calcnumUsed(int bit) {
    //bit에서 사용된 수의 갯수
    int ret = 0;
    while(bit > 0) {
        if(bit & 1) ret++;
        bit /= 2;
    }
    return ret;
}

long long numCase(int N,int bit) {
    //cout << "numCase call " << N << " " << bit << endl;
    //길이 N, bit상태를 가진 수 의 갯수
    //0을 사용해도됨
    if(N == 0 && bit == 0) return 1;
    if(N == 0) return 0;
    int nUsed = numUsed[bit];
    if(N == 1 && nUsed == 1) return 1;
    if(N == 1) return 0;
    if(N < nUsed) return 0;
    if(dp[N][bit] != -1) return dp[N][bit];

    long long ret = 0;
    //맨 첫자리 digit을 정한다
    for(int digit = 0;digit < N;digit++) {
        if(!(bit & (1<<digit))) continue; //해당 digit을 소유하지 않음
        ret += numCase(N-1,bit) + numCase(N-1,bit & (~(1<<digit))); //N-1길이에서 digit을 포함하거나 포함하지 않는 경우 둘다 누적
    }
    return dp[N][bit] = ret;
}
int main() {
    cin >> N >> K;
    vector<int> Nlist;
    int Nlen = 0;
    long long _N = N;
    while(_N > 0) {
        Nlist.push_back(_N%10);
        Nlen++;
        _N /= 10;
    }
    reverse(Nlist.begin(),Nlist.end());

    for(int bit = 0;bit < 1024;bit++) {
        numUsed[bit] = calcnumUsed(bit);
    }
    //dp initialize
    for(int i = 0;i < 19;i++) {
        for(int j = 0;j < 1024;j++) {
            dp[i][j] = -1;
        }
    }
    int max_bit = 1024;
    //N보다작고, 정확히 k개로 이루어진 수의 갯수 세기
    int count = 0;
    for(int index = 0;index < Nlen;index++) {
        //index digit을 정함
        int startdigit = 0;
        if(index == 0) startdigit = 1;
        //startdigit부터 Nlist[index]-1 까지 전부 더해주기
        for(;startdigit < Nlist[index];startdigit++) {
            //index 의 digit을 startdigit으로 정해줬음.
            //Nlist[0] .. Nlist[index-1] 까지의 digit 사용 비트 와 순회 비트를 합쳤을때 nUsed = k여야함
            int offset = (1<<startdigit);
            for(int j = 0;j < index;j++) offset |= (1<<Nlist[j]);
            for(int bit = 0;bit < max_bit;bit++) {
                int mixed_bit = bit | offset;
                if(numUsed[mixed_bit] != K) continue;
                count += numCase(Nlen-index-1,bit);
            }
        }
    }
    cout << count ;

    //해당 갯수 다음꺼 찾기
    return 0;
}