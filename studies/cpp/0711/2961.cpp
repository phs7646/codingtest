#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> S(N);
    vector<int> B(N);
    for(int i = 0;i < N;i++) cin >> S[i] >> B[i];
    int max_bit = 1 << N;
    int answer = 1000000007;
    for(int bit = 1;bit < max_bit;bit++) {
        int s = 1,b = 0;
        for(int i = 0;i < N;i++) {
            if(bit & (1<<i)) {
                s *= S[i];
                b += B[i];
            }
        }
        answer = min(answer,abs(s-b));
    }
    cout << answer;
    return 0;
}