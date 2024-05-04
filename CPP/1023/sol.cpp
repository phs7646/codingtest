#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0)); //dp[c][N] : N길이의 문자열 중 시작점이 c인 경우 괄호문자열의 갯수
    dp[0][0] = 1;  // 길이가 0이고 시작이 0인 경우는 빈 문자열 하나뿐

    for (int n = 1; n <= N; n++) {
        for (int c = 0; c <= N; c++) {
            if (c > 0) dp[c][n] += dp[c-1][n-1];  // 여는 괄호 추가
            if (c < N) dp[c][n]+= dp[c+1][n-1];  // 닫는 괄호 추가
        }
    }
    if( (1LL << N) - dp[0][N] <= K) {
        cout << -1;
        return 0;
    }

    int pos = 0;
    int c = 0;
    string answer = "";
    bool flag = true;
    while(pos < N && K > 0) {
        //pos번째 문자열 결정
        int length = N-1 - pos;
        long long num = (1LL << length);
        if(flag && c >= -1 && c < N-1) num -= dp[c+1][length]; //첫 문자를 (로 정했을때 괄호 ㄴㄴ 문자열의 갯수
        if(K >= num) {
            K -= num;
            answer.push_back(')');
            c-=1;
        } else {
            answer.push_back('(');
            c+=1;
        }
        if(c < 0) flag = false;
        pos++;
    }
    while(pos++ < N) answer.push_back('(');
    cout << answer;
    return 0;
}
