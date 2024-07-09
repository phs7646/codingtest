#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() { 
    int N,L,R,X;
    cin >> N >> L >> R >> X;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];

    int max_bit = 1 << N; // 000001 ~ 111111
    int answer = 0;
    for(int bit = 0;bit < max_bit;bit++) {
        int num_used = 0;
        int sum = 0;
        int _min = INT_MAX;
        int _max = 0;
        for(int i = 0;i < N;i++) {
            if(bit & (1<<i)) { //i번째 문제가 쓰였는지
                num_used++;
                sum += v[i];
                _min = min(_min,v[i]);
                _max = max(_max,v[i]); 
            }
        }
        if(num_used < 2) continue;
        if(sum < L || sum > R) continue;
        if(_max - _min < X) continue;
        answer++;
    }
    cout << answer;
    return 0;
}