#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;


long long solve(int mass, int A, int B) {
    if(mass == 0) return 0;
    if(mass < A) return -1;
    if(mass <= B) return 0;
    long long ret = 0;
    for(int detach = B;detach >= A;detach--) {
        long long c = solve(mass-detach,A,detach);
        if(c >= 0) return (long long) detach * (mass-detach) + c;
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N,A,B;
        cin >> N >> A >> B;
        unordered_map<int, long long> costs;
        long long answer = 0;
        int remain = N;

        while (remain > B) {
            remain -= B;
            answer += (long long) B * remain;
        }
        if(A <= remain && remain <= B) {
            cout << '#' << t << " " << answer << "\n";
            continue;
        }
        while (true) {
            //마지막 B덩어리 분리
            answer -= (long long) B * remain;
            remain += B;
            bool succ = false;
            for(int last = B-1; last >= A;last--) {
                // last만큼의 덩어리 부착하면 가능해?
                long long c = solve(remain-last,A,last);
                if(c >= 0) {
                    //가능하네! last부착
                    answer += (long long) last * remain;
                    answer += c;
                    succ = true;
                    break;
                }
            }
            if(succ) break;
            if(remain == N) {
                answer = -1;
                break;
            }
        }
        cout << '#' << t << " " << answer << "\n";
    }

    return 0;
}
