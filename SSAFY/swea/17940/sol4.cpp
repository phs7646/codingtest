#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;
int A,B;
long long solve(unordered_map<int,long long>& costs,int mass) {
    if(mass < A) return -1;
    if(mass <= B) return 0;
    if(costs[mass] != 0) return costs[mass];
    long long answer = LLONG_MAX;
    for(int detach = A;detach < B;detach++) {
        int remain = mass-detach;
        long long t = solve(costs,remain);
        if(t >= 0) {
            answer = min(answer,(long long) detach * remain + t);
            //break;
        }
    }
    if(answer == LLONG_MAX) answer = -1;
    costs[mass] = answer;
    //cout << "answer for " << mass << " is " << answer << endl;
    return answer;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    
    for(int t = 1;t <= T;t++) {
        int N;
        cin >> N >> A >> B;
        unordered_map<int,long long> costs;
        //B를 가능한 많이 뗄 수록 이득
        long long answer = 0;
        int remain = N;
        while(remain >= B) {
            remain -= B;
            answer += (long long) B * remain;
        }
        if(remain == 0) {
            cout << '#' << t << " " << answer << "\n";
            continue;
        }
        while(true) {
            //remain 을 만들 수 있는지 계산
            long long c = solve(costs, remain);
            if(c >= 0) {
                answer += c;
                break;
            }
            if(remain >= N) {
                answer = -1;
                break;
            }
            answer -= (long long) B * remain;
            remain += B;
        }
        cout << '#' << t << " " << answer << "\n";
        
    }

    return 0;
}