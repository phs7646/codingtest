#include<iostream>
#include<vector>
#include<string>
using namespace std;
int digitNum[] = {6,2,5,5,4,5,6,3,7,5};
long long dp[15+1][7*15+1];
long long countCase(int N,long long sum) {
    //N자리로 sum을 만드는 경우의수!

    //예외 케이스
    if(N==0 && sum==0) return 1;
    if(N==0) return 0;
    if(sum < 0 || sum > N*7) return 0;
    if(N==1) return dp[1][sum];
    if(dp[N][sum] != -1) return dp[N][sum];

    //dp 로직
    long long answer = 0;
    //맨 앞자리를 고르자
    for(int first = 0;first <= 9;first++) {
        answer += countCase(N-1,sum-digitNum[first]);
    }
    return dp[N][sum] = answer;
}

int main() {
    string s; cin >> s;
    int N = s.size();
    //dp initialize
    for(int i = 2;i <= N;i++) {
        for(long long sum = 0;sum <= 7*i;sum++) {
            dp[i][sum] = -1;
        }
    }
    for(int sum = 0;sum <= 7;sum++) dp[1][sum] = 0;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 4;
    dp[1][6] = 2;
    dp[1][7] = 1;
    
    //s의 sum 구하기
    int sum = 0;
    for(char c : s) sum += digitNum[c-'0'];
    // cout << "N의 sum: " << sum << endl;
    //N에서 sum 이 총 몇개인지 구하기
    long long total = countCase(N,sum);
    // cout << "총 갯수: " << total << endl;
    //s가 몇번째 수인지 구하기 = s보다 작은 sum이 몇개 있는가?
    long long sPos = 0;
    long long _sum = sum;
    for(int i = 0;i < N;i++) {
        //i번째 문자
        int digit = s[i]-'0';
        //digit까지의 N-i-1 길이 전부 더하기
        for(int d = 0;d < digit;d++) {
            sPos += countCase(N-1-i,_sum-digitNum[d]);
        }
        _sum -= digitNum[digit];
    }
    // cout << "s의 위치: " << sPos << endl;
    //s가 마지막 수라면 가장 처음수, 아니라면 그다음수를 갯수를통해 찾아가기 
    long long target = sPos+1;
    if(target >= total) target = 0;
    vector<int> s2(N);
    long long current = 0;
    _sum = sum;
    for(int i = 0;i < N;i++) {
        //i번째 자리 결정하기
        for(int digit = 0;digit <= 9;digit++) {
            long long n = countCase(N-i-1,_sum-digitNum[digit]);
            //cout << i << "번째 자리에  " << digit << "을 넣으면 갯수가 " << n <<endl;
            //cout << "이 때 sum : " << _sum-digitNum[digit] << endl;
            if(current + n > target) {
                break;
            }
            current += n;
            s2[i]++;
        }
        _sum -= digitNum[s2[i]];
    }
    //cout << "다음 수: ";
    //for(int k : s2) cout << k;
    //cout << endl;
    long long sValue = 0;
    for(char c : s) sValue = sValue*10 + (c-'0');
    long long nextValue = 0;
    for(int k : s2) nextValue = nextValue*10 + k;
    long long answer = nextValue - sValue;
    if(answer <= 0) {
        //한바퀴 더 돌아야함
        long long tenpow=1;
        for(int i = 0;i < N;i++) tenpow*=10;
        answer += tenpow;
    }
    cout << answer;

    return 0;
}