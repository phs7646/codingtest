#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N,S;
    cin >> N >> S;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    
    int answer = N+1;
    int start = 0, end = 0;
    int sum = 0;
    while(true) {
        if(sum >= S) {
            answer = min(answer,end - start);
            sum -= v[start];
            start++;
        } else if (end == N) {
            break;
        } else {
            sum += v[end];
            end++;
        }
    }
    if(answer == N+1) answer = 0;
    cout << answer;
    return 0;
}