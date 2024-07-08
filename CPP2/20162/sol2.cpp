#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    vector<int> dp(N); //dp[i] : i번째를 먹었을 때 최댓 값..
    dp[0] = v[0];
    for(int i = 1;i < N;i++) {
        dp[i] = v[i];
        for(int j = 0;j < i;j++) {
            if(v[j] < v[i]) dp[i] = max(dp[i],dp[j]+v[i]);
        }
    }
    cout << *max_element(dp.begin(),dp.end());
    return 0;
}