#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int N,int A,int B) {    
    int sum_k = 0;
    int answer = 0;
    vector<pair<int,int>> v(N);
    for(int i = 0;i < N;i++) {
        int a,b,k;
        cin >> k >> a >> b;
        answer += a * k;
        sum_k += k;
        v[i] = {b-a,k};
    }
    sort(v.begin(),v.end());

    //B로 바꾸는 범위 : 최소 max(sum_k-A,0) ~ 최대 min(sum_k,B)
    int c_min = max(sum_k-A , 0);
    int c_max = min(sum_k , B);

    int count = 0;
    while(true) {
        auto pair = v.front();
        if(count < c_min) {
            //must change
            if(c_min-count >= pair.second) {
                answer += pair.first * pair.second;
                count += pair.second;
                v.erase(v.begin());
            } else {
                int num_change = c_min-count;
                answer += pair.first * num_change;
                count += num_change;
                v[0] = {pair.first,pair.second-num_change};
            }
        } else if (count < c_max && v[0].first < 0) {
            //take v[0]
            if(c_max - count >= pair.second) {
                answer += pair.first * pair.second;
                count += pair.second;
                v.erase(v.begin());
            } else {
                int num_change = c_max-count;
                answer += pair.first * num_change;
                count += num_change;
                v[0] = {pair.first,pair.second-num_change};
            }
        } else break;
    }

    cout << answer << "\n";
}

int main() {
    int N,A,B;
    while(true) {
        cin >> N >> A >> B;
        if(N == 0) break;
        else solve(N,A,B);
    }
    return 0;
}