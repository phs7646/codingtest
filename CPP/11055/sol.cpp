#include<iostream>
#include<vector>

using namespace std;

/* helper functions */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}

template<typename T>
vector<T> vectorinput(int n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

/* codes */

int main() {
    int N;
    cin >> N;
    vector<int> v = vectorinput<int>(N);
    vector<int> dp = vector<int>(N,0); //dp[i] = i를 택했을 때 i까지의 최댓값
    dp[0] = v[0];

    int answer= v[0];
    for(int i = 1;i < N;i++) {
        int maximum = v[i];
        for(int j = 0;j < i;j++) {
            if(v[j] < v[i]) maximum = max(maximum,dp[j] + v[i]);
        }
        dp[i] = maximum;
        answer = max(answer,dp[i]);
    }
    cout << answer;
    return 0;
}