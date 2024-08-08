#include<iostream>
#include<climits>
#include<cmath>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;

unordered_map<ll,ll> dp;

ll solve(ll N) {
    if(N == 1) return 0;
    if(N == 2) return 1;
    if(dp.find(N) != dp.end()) return dp[N];
    ll left = static_cast<ll>(sqrt(N));
    ll right = left+1;
    ll ret = N-1;
    ret = min(ret,solve(left) + (N-left*left) + 1);
    ret = min(ret,solve(right) + (right*right-N) + 1);
    dp[N] = ret;
    cout << "solve " << N << " is " << ret << endl;
    return ret;
}

int main() {
    ll N; cin >> N;
    cout << solve(N);
    return 0;
}