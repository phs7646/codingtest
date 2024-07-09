#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define INT_MAX 2147483647
int main() {
    int N;
    cin >> N;

    vector<int> vec;

    for(int i = 0;i < N;i++) {
        int value;
        cin >> value;
        auto it = std::lower_bound(vec.begin(),vec.end(),value);
        vec.insert(it,value);
    }

    int min = vec.at(0);
    int max = min + 17;
    int ans = INT_MAX;
    while(max <= vec.back()) {
        //cost calculation
        int cost = 0;
        //lower
        for(auto it = vec.begin(); it < vec.end(); it++) {
            if(*it >= min) break;
            cost += (min-*it) * (min-*it);
        }
        for(auto it = vec.end()-1;it >= vec.begin();it--) {
            if(*it <= max) break;
            cost += (*it-max) * (*it-max);
        }
        //cost update
        if(ans > cost) ans = cost;
        min++;
        max++;
    }
    cout << ans;

    return 0;
}