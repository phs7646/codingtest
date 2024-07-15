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
    for(int detach = A;detach <= B;detach++) {
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
        //solve(costs,N);
        //B+1부터 N까지의 dp를 계산
        cout << '#' << t << " " << solve(costs,N) << "\n";
        
    }

    return 0;
}