#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int k;
unordered_map<int,int> memo;
vector<int> p(10);

/*
*   history 내부의 모든 수들에 대해 memo
*   0~9까지의 pow 계산 결과를 미리 저장
*/

int next(int n) {
    int ret = 0;
    while(n  > 0) {
        ret +=p[n%10];
        n = n / 10;
    }
    return ret;
}

int solve(int n) {
    if(memo[n] > 0) return memo[n];
    int min = n;
    vector<int> history;
    history.push_back(n);
    int prev = n;
    while(true) {
        int now = next(prev);
        if(memo[now] > 0) {
            if(min > memo[now]) min = memo[now];
            break;
        }
        if(now < min) min = now;
        auto it = find(history.begin(),history.end(),now);
        if(it != history.end()) {
            //found cycle
            int min_cycle = *min_element(it,history.end());
            for(auto it2 = it;it2 < history.end();it2++) {
                memo[*it2] = min_cycle; 
            }
            break;
        }
        
        history.push_back(now);
        prev = now;
        
    }
    memo[n] = min;
    return min;
}

int main() {
    int A,B;
    cin >> A >> B >> k;

    for(int i = 0;i <= 9;i++) {
        p[i] = static_cast<int>(pow(i,k));
    }

    long long sum = 0;
    for(int i = A;i <=B;i++) {
        sum += static_cast<long long>(solve(i));
    }
    cout << sum;
    return 0;
}