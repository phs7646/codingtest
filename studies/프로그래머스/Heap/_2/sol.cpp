#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //{처리시간, 요청시간}
    
    int time = 0;
    int index = 0;
    
    while(true) {
        //exit condition
        if(index >= size && pq.empty()) break;
        
        //push everything that can start now
        while(index < size && jobs[index][0] <= time) {
            pq.push({jobs[index][1],jobs[index][0]});
            index++;
        }
        
        //if nothing possible, skip
        if(index < size && pq.empty()) {
            time = jobs[index][0];
            continue;
        }
            
        //pick which process to run
        int target_duration = pq.top().first;
        int target_start = pq.top().second;
        pq.pop();
        //time ~ duration
        time += target_duration;
        answer += (time - target_start);
    }
    
    return answer/size;
}