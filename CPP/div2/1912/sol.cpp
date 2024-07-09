#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    vector<int> dp(N);
    int answer = INT_MIN;
    for(int i = 0;i < N;i++) {
        dp[i] = v[i];
        answer = max(answer,dp[i]);
    }

    for(int dist = 1;dist < N-1;dist++) {
        //dp[i] : i부터 dist만큼의 수열의 합
        for(int i = 0;i < N-dist-1;i++) {
            dp[i] += v[i+dist];
            answer = max(answer,dp[i]);
        }
    }

    cout << answer;

    return 0;
}