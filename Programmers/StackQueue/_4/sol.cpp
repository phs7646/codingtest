#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int,int>> q;
    for(int i = 0;i < priorities.size();i++) {
        q.push({priorities[i],i});
    }
    
    sort(priorities.begin(),priorities.end(),greater<int>());
    int index = 0;
    int count = 0;
    while(!q.empty()) {
        auto pair = q.front();
        q.pop();
        
        if(pair.first == priorities[index]) {
            count++;
            if(pair.second == location) return count;
            index++;
        } else {
            q.push(pair);
        }
    }
    
}