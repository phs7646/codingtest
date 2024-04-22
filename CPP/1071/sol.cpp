#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void orderedinput(vector<int>& v, int k) {
    v.insert(upper_bound(v.begin(),v.end(),k),k);
}



int main() {
    int N;
    cin >> N;
    vector<int> origin;
    for(int i = 0;i < N;i++) {
        int k;
        cin >> k;
        orderedinput(origin,k);
    }
    bool flag = false;
    vector<int> answer;
    while(answer.size() < N) {
        //pick smallest possible element
        auto it = origin.begin();
        while(it < origin.end()) {
            int pick = *it;
            if(answer.empty() || answer.back() + 1 != pick) {
                if(flag) {
                    flag = false;
                    //cout << "skip " << pick << "\n";
                } else {
                    break;
                }
            }
            do {
                it++;
            } while(it < origin.end() && *it <= pick);
        }

        if(it == origin.end()) {
            //nothing possible.. must go back
            int pop = answer.back();
            //cout << "detach " << pop << "\n";
            answer.pop_back();
            orderedinput(origin,pop);
            flag = true;
        } else {
            //cout << "attach " << *it << "\n";
            answer.push_back(*it);
            origin.erase(it);
        }
    }

    for(int n : answer) cout << n << " ";

    return 0;
}