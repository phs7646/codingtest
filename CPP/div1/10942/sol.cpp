#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

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

int main() {
    int N;
    cin >> N;
    vector<int> v = vectorinput<int>(N);
    vector<vector<int>> dp(N, vector<int>(N));

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0;i < N;i++) dp[i][i] = 1;
    for(int i = 0;i < N-1;i++) {
        if(v[i] == v[i+1]) dp[i][i+1] = 1;
    }

    for(int dist = 2; dist <= N-1; dist++) {
        for(int i = 0;i < N-dist;i++) {
            dp[i][i+dist] = (v[i] == v[i+dist]) && dp[i+1][i+dist-1];
        }
    }

    int T;
    cin >> T;
    stringstream output;
    for(int t = 0;t < T;t++) {
        int a,b;
        cin >> a >> b;
        output << dp[a-1][b-1] << "\n";
    }
    cout << output.str();

    return 0;
}

