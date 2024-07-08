#include<iostream>
#include<vector>

using namespace std;
int dp[100007];
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < v[i];j++) {
            dp[v[i]] = max(dp[v[i]],dp[j]+v[i]);
        }
    }
    int answer = 0;
    for(int i = 0;i < 100000;i++) answer = max(answer,dp[i]);
    cout << answer;
    return 0;
}