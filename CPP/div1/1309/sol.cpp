#include<iostream>
#include<vector>

using namespace std;


int main() {
    int N;
    cin >> N;
    if(N == 0) {
        cout << 1;
        return 0;
    }
    int MOD = 9901;
    vector<int> dp1(N); //위에 배치
    vector<int> dp2(N); //아래 배치
    vector<int> dp3(N); //둘다 없음
    dp1[0] = 1;
    dp2[0] = 1;
    dp3[0] = 1;
    for(int i = 1;i < N;i++) {
        dp1[i] = (dp2[i-1] + dp3[i-1])%MOD;
        dp2[i] = (dp1[i-1] + dp3[i-1])%MOD;
        dp3[i] = (dp1[i-1] + dp2[i-1] + dp3[i-1])%MOD;
    }
    cout << (dp1[N-1] + dp2[N-1] + dp3[N-1])%MOD;

    return 0;
}