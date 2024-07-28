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

        //로직
        long long answer = 0;

        long long numB = N / B;
        int remain = N % B;
        int diff = B-A;
        long long numA = 0;
        if(A < remain) {
            numA = (A-remain)/diff;
            if((A-remain)%diff != 0) numA++;
            numB -= numA;
            remain += numA * diff;
        }
        if(numB >= 0) {
            //B가 numB개 A가 numA개 + remain
            if(numB > 0) answer += B * (numB*remain + (numB-1)*numB/2 * B);
            if(numA > 0) answer += A * (numA*(remain+numB*B) + (numA-1)*numA/2 * A);
        } else {
            answer = -1;
        }

        cout << '#' << t << " " << answer << "\n";
    }

    return 0;
}
