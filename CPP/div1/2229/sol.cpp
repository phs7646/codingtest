#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0;i < N;i++) cin >> arr[i];
    vector<vector<int>> dp(N,vector<int>(N)); //dp[i][j] : i번부터 j번 멤버만 사용했을 때 최댓값
    
    for(int dist = 1;dist < N;dist++) {
        for(int i = 0;i < N-dist;i++) {
            //dp[i][i+dist]를 계산
            int maximum = 0;
            //통째로 한조로 묶는 경우
            int _max = arr[i];
            int _min = arr[i];
            for(int j = i+1;j <= i+dist;j++) {
                _max = max(_max,arr[j]);
                _min = min(_min,arr[j]);
            }
            maximum = max(maximum,_max-_min);
            //두개의 그룹으로 나눔
            for(int j = i;j < i+dist;j++) {
                maximum = max(maximum,dp[i][j] + dp[j+1][i+dist]);
            }
            dp[i][i+dist] = maximum;
        }
    }
    cout << dp[0][N-1];
    return 0;
}