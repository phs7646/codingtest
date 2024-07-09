#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

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
    int N,K;
    cin >> N >> K;
    vector<vector<int>> map(N);
    for(int i = 0;i < N;i++) map[i] = vectorinput<int>(N);

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    vector<vector<int>> dp((1<<N),vector<int>(N,INT_MAX));
    dp[1<<K][K] = 0;
    queue<pair<int,int>> q;
    q.push({1<<K,K});
    while(!q.empty()) {
        auto pair = q.front();
        int bit = pair.first;
        int last = pair.second;
        q.pop();
        for(int i = 0;i < N;i++) {
            if(bit & (1<<i)) continue;
            int new_bit = bit | (1<<i);
            int new_cost = dp[bit][last] + map[last][i];
            if(dp[new_bit][i] > new_cost) {
                dp[new_bit][i] = new_cost;
                q.push({new_bit,i});
            }
        }
    }
    cout << *min_element(dp[((1<<N)-1)].begin(),dp[((1<<N)-1)].end());
    return 0;
}