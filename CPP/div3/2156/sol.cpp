#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int dp[10000][2];
int main() {
    int N; cin >> N;
    for(int i = 0;i < N;i++) cin >> arr[i];
    if(N==1) {
        cout << arr[0];
        return 0;
    }
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    dp[1][0] = arr[1];
    dp[1][1] = arr[0] + arr[1];
    dp[2][0] = arr[0] + arr[2];
    dp[2][1] = arr[1] + arr[2];
    for(int i = 3;i < N;i++) {
        //dp[i][0]
        dp[i][0] = arr[i] + max(max(dp[i-2][0],dp[i-2][1]), max(dp[i-3][0],dp[i-3][1]));
        //dp[i][1]
        dp[i][1] = arr[i] + dp[i-1][0];
    }
    /*
    for(int i = 0;i < N;i++) {
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    */
    cout << max(max(dp[N-2][0],dp[N-2][1]),max(dp[N-1][0],dp[N-1][1]));
    return 0;
}