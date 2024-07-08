#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v;
    int answer = INT_MIN;
    for(int i = 0;i < N;i++) {
        int tmp;
        cin >> tmp;
        answer = max(answer,tmp);
        if(tmp == 0) continue;
        if(v.empty()) {
            if(tmp > 0) v.push_back(tmp);
        }
        else if(tmp > 0) {
            if(v.back() > 0) v[v.size()-1] += tmp;
            else v.push_back(tmp);
        }
        else {
            if(v.back() < 0) v[v.size()-1] += tmp;
            else v.push_back(tmp);
        }
    }
    if(v.size() == 0) {
        cout << answer;
        return 0;
    } else if(v.size() == 1) {
        if(v[0] > 0) cout << v[0];
        else cout << answer;
        return 0;
    }
    //v의 짝수번째에 양수가 들어있음.
    N = v.size();
    //for(int n : v) cout << n << " ";
    //cout << endl;
    vector<vector<int>> dp(N,vector<int>(2,INT_MIN));
    dp[0][0] = v[0]; //최댓값
    dp[0][1] = v[0]; //가장 오른쪽 값을 반드시 포함하는 최댓값
    for(int i = 2;i < N;i+=2) {
        //그냥 맨 오른쪽이 최댓값 이거나, 이전 최댓값에 오른쪽을 붙인 것
        dp[i][1] = max(v[i],dp[i-2][1] + v[i-1] + v[i]);
        dp[i][0] = max(dp[i-2][0],dp[i][1]);
        //cout << i << " : " << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << max(dp[N-2][0],dp[N-1][0]);
    return 0;
}