#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    int left = 1000000000;
    for(int i = 0;i < N;i++) {
        int a,b;
        cin >> a >> b;
        if(a > b) {
            int t = a;
            a = b;
            b = t;
        }
        left = min(left,a);
        v[i] = {a,b};
    }
    int d;
    cin >> d;

    //set initial state
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> active;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> cand;
    int right = left+d;
    for(auto pair : v) {
        if(pair.second <= right) active.push(pair); //{start,end}
        else cand.push({pair.second,pair.first}); // {end,start}
    }
    int answer = active.size();

    //cout << "Before start active is " << active.size() << endl;
    //loop
    while(!cand.empty()) {
        //put next cand
        auto next = cand.top();
        //cout << "Put " << next.second << " " << next.first << endl;
        cand.pop();
        int dist = next.first - right;
        right += dist;
        left += dist;
        active.push({next.second,next.first});
        //pop from active
        while(!active.empty() && active.top().first < left) active.pop();
        //cout << "After pop " << active.size() << " remain " << endl;
        if(answer < active.size()) answer = active.size();
    }

    cout << answer;
    return 0;
}