#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int s : scoville) pq.push(s);
    while(pq.size() >= 2 && pq.top() < K) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
        answer++;
    }
    if(pq.top() >= K) return answer;
    else return -1;
}