#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;


    vector<vector<int>> after(N+1); // v[i] : 뒤에 나오는 가수들
    vector<int> count(N+1,0); // count[i] : i번보다 먼저 나와야하는 가수의 수
    for(int i = 0;i < M;i++) {
        int k;
        cin >> k;
        vector<int> v(k);
        for(int j = 0;j < k;j++) {
            cin >> v[j];
            count[v[j]] += j;
        }
        for(int j = 1;j < k;j++) {
            for(int q = 0;q < j;q++) {
                after[v[q]].push_back(v[j]);
            }
        }
    }

    queue<int> q;
    vector<int> answer;
    for(int i = 1;i <= N;i++) {
        if(count[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int f = q.front();
        q.pop();
        answer.push_back(f);
        for(int a : after[f]) {
            count[a]--;
            if(count[a] == 0) q.push(a);
        }
    }

    if(answer.size() < N) cout << 0;
    else {
        for(int i : answer) cout << i << "\n";
    }
    return 0;
}