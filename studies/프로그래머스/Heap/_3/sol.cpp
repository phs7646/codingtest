#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ordered_input(vector<int>& v, int item) {
    auto it = lower_bound(v.begin(),v.end(),item);
    v.insert(it,item);
}

void pop_max(vector<int>& v) {
    if(v.empty()) return;
    v.erase(v.end()-1);
}

void pop_min(vector<int>& v) {
    if(v.empty()) return;
    v.erase(v.begin());
}

vector<int> solution(vector<string> operations) {
    vector<int> v;
    for(string s : operations) {
        if(s[0] == 'I') ordered_input(v,stoi(s.substr(2)));
        else if(stoi(s.substr(2)) == 1) {
            pop_max(v);
        } else {
            pop_min(v);
        }
    }
    vector<int> answer(2,0);
    if(v.size() > 0) {
        answer[0] = v.back();
        answer[1] = v.front();
    }
    
    return answer;
}