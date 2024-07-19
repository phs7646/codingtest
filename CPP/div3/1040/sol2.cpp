#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned long long N;
int K;
unsigned long long dp[20][1024];
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
unsigned long long brute_numCase(int N,int bit) {
    unsigned long long ret = 0;
    //길이가 N인 수 중 bit를 만족하는 수의 갯수 세기
    //1...0부터 10^N-1
    unsigned long long end = 1;
    for(int i = 0;i < N;i++) end *= 10;
    for(unsigned long long start = 0;start < end;start++) {
        unsigned long long t = start;
        int check = 0;
        while(t > 0) {
            int digit = t % 10;
            check |= (1<<digit);
            t /= 10;
        }
        if(start < end/10) check |= 1; //0도사용함
        if(bit == check) {
            ret++;
        }
    }
    return ret;
}
unsigned long long numCase(int N,int bit) {
    //cout << "numCase call " << N << " " << bit << endl;
    //길이 N, bit상태를 가진 수 의 갯수
    //0을 사용해도됨
    if(N == 0 && bit == 0) return 1;
    if(N == 0) return 0;
    int nUsed = numUsed[bit];
    if(N == 1 && nUsed == 1) return 1;
    if(N == 1) return 0;
    if(N < nUsed) return 0;
    //cout << N << " " << bit << endl;
    if(dp[N][bit] != -1) return dp[N][bit];

    unsigned long long ret = 0;
    //맨 첫자리 digit을 정한다
    for(int digit = 0;digit <= 9;digit++) {
        if(!(bit & (1<<digit))) continue; //해당 digit을 소유하지 않음
        ret += numCase(N-1,bit) + numCase(N-1,bit & (~(1<<digit))); //N-1길이에서 digit을 포함하거나 포함하지 않는 경우 둘다 누적
    }
    //if(brute_numCase(N,bit) != ret) {
    //    cout << N << "길이, " << bit << "에서 답이 다름. 정답은 " << brute_numCase(N,bit) << "인데 출력은 " << ret << endl;
    //}
    return dp[N][bit] = ret;
}
int main() {
    cin >> N >> K;
    vector<int> Nlist;
    int Nlen = 0;
    unsigned long long _N = N;
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
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(unsigned long long), -1);
    int max_bit = 1024;
    //N보다작고, 정확히 k개로 이루어진 수의 갯수 세기
    unsigned long long count = 0;
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
    //cout << "count is " <<  count << endl;
    //k개로 이루어진 count+1번째 수 찾기
    unsigned long long accum = 0;
    unsigned long long target = count+1;
    while(true) {
        //cout << "Loop start" << endl;
        //Nlen부터 찾기
        vector<int> history;
        for(int index = 0;index < Nlen;index++) {
            int fdigit = 0;
            if(index == 0) fdigit = 1;
            for(;fdigit<=9;fdigit++) {
                //fdigit을 골랐을 때 갯수
                unsigned long long cur = 0;
                int offset = 1<<fdigit;
                for(int d : history) offset |= 1<<d;
                for(int bit = 0;bit < 1024;bit++) {
                    int mixed_bit = bit | offset;
                    if(numUsed[mixed_bit] == K) cur += numCase(Nlen-index-1,bit);
                }
                //cout << fdigit << "을 고르면 " << cur << endl;
                if(accum + cur >= target) {
                    //지금 digit으로 선택
                    //cout << "pick " << fdigit << endl;
                    history.push_back(fdigit);
                    break;
                } else {
                    accum += cur;
                }
            }
            if(fdigit == 10) {
                //못찾았다;;
                break;
            }
        }
        if(history.size() < Nlen) {
            Nlen++;
            //accum = 0;
            history.resize(0);
        } else {
            //history 출력하기
            for(int h : history) cout << h;
            return 0;
        }
    }

    //해당 갯수 다음꺼 찾기
    return 0;
}