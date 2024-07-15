#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, A, B;
        cin >> N >> A >> B;

        // 예외 처리
        if (N < A) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }
        if (N <= B) {
            cout << '#' << t << " " << 0 << "\n";
            continue;
        }
        if(N % B == 0) {
            long long answer = 0;
            int remain = N-B;
            while(remain >= B) {
                answer += (long long) B * remain;
                remain -= B;
            }
            cout << '#' << t << " " << answer << "\n";
            continue;
        }
        if(A == B) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }
        cout << '#' << t << " " << -1 << "\n";
        continue;
        long long answer = LLONG_MAX;

        int maxB = N / B;

        for (int b = maxB; b >= 0; b--) {
            int remain = N - b * B;
            //remain을 만들 수 있는가..??
        }

        if (answer == LLONG_MAX) {
            cout << '#' << t << " " << -1 << "\n";
        } else {
            cout << '#' << t << " " << answer << "\n";
        }
    }

    return 0;
}
