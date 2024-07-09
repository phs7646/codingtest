#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    
    vector<pair<int,int>> jewel(N);
    for(int i = 0;i < N;i++) {
        int m,v;
        cin >> m >> v;
        jewel[i] = {m,v};
    }
    sort(jewel.begin(),jewel.end());

    vector<int> bag(K);
    for(int i = 0;i < K;i++) cin >> bag[i];
    sort(bag.begin(),bag.end());

    priority_queue<int> pq;

    long long answer = 0;
    int cursor = 0;
    
    for(int i = 0;i < K;i++) {
        while(cursor < N && jewel[cursor].first <= bag[i]) {
            pq.push(jewel[cursor].second);
            cursor++;
        }
        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
    return 0;
}