#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> X;
int P,Q;
vector<int> nums;

int answer = 0;
void dfs(int pos) {
    if(pos == N) {
        int ret = 1;
        for(int k : nums) ret *= k;
        answer = max(answer,ret);
        return;
    }
    for(int i = 0;i <= min(Q,pos);i++) {
        //pos를 i에 배치
        nums[i] += X[pos];
        dfs(pos+1);
        nums[i] -= X[pos];
    }
}

int main() {
    cin >> N;
    X.resize(N);
    for(int i = 0;i < N;i++) cin >> X[i];
    cin >> P >> Q;
    if(N==1) {
        cout << X[0];
        return 0;
    }
    nums.resize(Q+1);
    nums[0] = X[0];
    dfs(1);
    cout << answer;
    return 0;
}