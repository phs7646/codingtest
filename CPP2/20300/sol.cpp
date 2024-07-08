#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> t(N);
    for(int i = 0;i < N;i++) cin >> t[i];
    sort(t.begin(),t.end());
    long long m = 0;
    if(N%2 == 1) {
        m = t[N-1];
        N--;
    }
    m = max(m,t[0] + t[N-1]);
    for(int i = 1;i <= N/2;i++) {
        m = max(m,t[i]+t[N-i-1]);
    }
    cout << m;
    return 0;
}