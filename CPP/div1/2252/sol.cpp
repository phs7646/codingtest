#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<int> count(N+1,0);

    for(int i = 0;i < M;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        count[b]++;
    }

    
    queue<int> zeros;
    for(int i = 1;i <= N;i++) {
        if(count[i]==0) zeros.push(i);
    }

    vector<int> answer;
    while(!zeros.empty()) {
        int target = zeros.front();
        zeros.pop();
        answer.push_back(target);
        for(int n : graph[target]) {
            count[n]--;
            if(count[n] == 0) zeros.push(n);
        }
    }

    for(int n : answer) cout << n << " ";

    return 0;
}