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

        long long answer = LLONG_MAX;
        bool found = false;

        // numB를 최대치부터 줄여가며 numA를 찾는 방식
        for (int numB = N / B; numB >= 0; --numB) {
            int left = N - numB * B;
            if (left >= A && left <= B) {
                found = true;
                long long cost = 0;

                // B 덩어리들의 비용 계산
                if (numB > 0) {
                    cost += (long long)B * (numB * left + (numB - 1) * numB / 2 * B);
                }

                // A 덩어리들의 비용 계산
                if (left >= A && left <= B) {
                    cost += (long long)left * (numB * B);
                }

                answer = min(answer, cost);
                break;
            }
        }

        if (!found) {
            cout << '#' << t << " " << -1 << "\n";
        } else {
            cout << '#' << t << " " << answer << "\n";
        }
    }

    return 0;
}
