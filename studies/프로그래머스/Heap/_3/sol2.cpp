#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for(string s : operations) {
        if(s[0] == 'I') ms.insert(stoi(s.substr(2)));
        else if(stoi(s.substr(2)) == 1) {
            if(!ms.empty()) ms.erase(prev(ms.end()));
        } else {
            if(!ms.empty()) ms.erase(ms.begin());
        }
    }
    vector<int> answer(2,0);
    if(!ms.empty()) {
        answer[0] = *(prev(ms.end()));
        answer[1] = *ms.begin();
    }
    
    return answer;
}