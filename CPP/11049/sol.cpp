#include<iostream>
#include<vector>
#include<climits>

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
    vector<long long> R(N);
    vector<long long> C(N);
    for(int i = 0;i < N;i++) cin >> R[i] >> C[i];
    vector<vector<long long>> dp(N,vector<long long>(N,0));
    //for(int i = 0;i < N;i++) dp[i][i] = 0;
    for(int i = 0;i < N-1;i++) dp[i][i+1] = R[i] * C[i] * C[i+1];

    for(int dist = 2; dist <= N-1;dist++) {
        for(int i = 0;i < N-dist;i++) {
            int j = i + dist;
            //calculate d[i][j]
            long long minimum = LLONG_MAX;
            for(int k = i;k < j;k++) {
                minimum = min(minimum, dp[i][k] + dp[k+1][j] + R[i] * C[k] * C[j]);
            }
            dp[i][j] = minimum;
        }
    }
    cout << dp[0][N-1];

    return 0;
}