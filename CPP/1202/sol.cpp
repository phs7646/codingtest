#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    
    vector<pair<int,int>> jewel(N);
    for(int i = 0;i < N;i++) {
        int m,v;
        cin >> m >> v;
        jewel.push_back({v,m});
    }
    sort(jewel.begin(),jewel.end(),greater<pair<int,int>>());

    vector<int> bag(K);
    for(int i = 0;i < K;i++) cin >> bag[i];
    sort(bag.begin(),bag.end());

    long long answer = 0;
    for(int i = 0;i < N;i++) {
        auto it = lower_bound(bag.begin(),bag.end(),jewel[i].second);
        if(it == bag.end()) continue;
        answer += jewel[i].first;
        bag.erase(it);
        if(bag.empty()) break;
    }
    cout << answer;
    return 0;
}