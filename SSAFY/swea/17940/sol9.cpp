#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

long long calcul(int A, int numA) {
    if(numA == 0) return 0;
    //A인 덩어리 numA개
    long long whole = static_cast<long long>(A) * numA;
    long long part1 = whole * numA;
    long long part2 = (static_cast<long long>(numA) * (numA + 1) / 2) * A;
    return A * (part1 - part2);
}

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
        int numA = 0;
        int numB = N/B;
        int diff = B-A;
        for(;numB>=0;numB--) {
            int left = N - numB * B;
            numA = left / A;
            long long remain = left%A;
            if(remain == 0 || (numA > 0 && remain <= diff)) {
                //possible case. calculate
                if(numA > 0) {
                    remain += A;
                    numA--;
                }
                long long cur = 0;
                //numA numB remain 세덩어리로 분류
                cur += calcul(A,numA);
                cur += calcul(B,numB);
                long long Atotal = A * numA;
                long long Btotal = B * numB;
                cur += Atotal * Btotal + Atotal * remain + remain * Btotal;
                answer = min(answer,cur);
            }
            if(diff == 0) break;
        }
        if(answer == LLONG_MAX) cout << '#' << t << " " << -1 << "\n";
        else cout << '#' << t << " " << answer << "\n";
    }

    return 0;
}
