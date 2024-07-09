#include<iostream>
#include<vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> dp0(41);
    vector<int> dp1(41);
    dp0[0] = 1;
    dp1[1] = 1;
    for(int i = 2;i <= 40;i++) {
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    }
    for(int t = 0;t < T;t++){
        int n;
        cin >> n;
        cout << dp0[n] << " " << dp1[n] << "\n";
    }
    return 0;
}