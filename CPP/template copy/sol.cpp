#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    while(index < progresses.size()) {
        int d = (100 - progresses[index] + speeds[index] - 1) / speeds[index];
    
        for(int i = index+1;i < progresses.size();i++) {
            if(progresses[i] >= 100) continue;
            progresses[i] = progresses[i] + speeds[i] * d;
        }
        
        int count = 0;
        while(index < progresses.size() && progresses[index] >= 100) {
            index++;
            count++;
        }
        answer.push_back(count);
        cout << count << "\n";
    }
    
    return answer;
}