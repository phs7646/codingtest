#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N,0);
    priority_queue<pair<int,int>> pq; //{price, index}
    for(int i = 0;i < N;i++) {
        while(!pq.empty() && pq.top().first > prices[i]) {
            int index = pq.top().second;
            pq.pop();
            answer[index] = i-index;
        }
        pq.push({prices[i],i});
    }
    while(!pq.empty()) {
        answer[pq.top().second] = N-pq.top().second-1;
        pq.pop();
    }
    return answer;
}