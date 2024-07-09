#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        //입력
        int N,M,K;
        cin >> N >> M >> K;
        vector<int> v(N);
        for(int i = 0;i < N;i++) cin >> v[i];

        int answer = 0; //가짓수
        int current = 0; //현재 케이스에서 훔친 돈

        //첫번째 케이스, 즉 0번집을 먼저 골랐을 때 계산
        for(int i = 0;i < M;i++) {
            current += v[i];
        }
        if(current < K) answer++;

        //N == M 이면 한가지 케이스만 존재
        if(N == M) {
            cout << answer << "\n";
            continue;
        }
        
        for(int i = 1;i < N;i++) {
            //i번 째 집을 첫 집으로 골랐을 때 계산
            current -= v[i-1];
            current += v[(i+M-1)%N];
            if(current < K) answer++;
        }
        cout << answer << "\n";
    }
    return 0;
}