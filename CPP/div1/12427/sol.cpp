#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> tree(N);
    for(int i = 0;i < N;i++) {
        cin >> tree[i];
    }
    vector<int> grow(N);
    for(int i = 0;i < N;i++) {
        cin >> grow[i];
    }

    vector<pair<int,int>> v;
    for(int i = 0;i < N;i++) v.push_back({grow[i],tree[i]});
    sort(v.begin(),v.end());
    long long answer = 0;
    for(int i = 0;i < N;i++) {
        answer += v[i].second + v[i].first*i;
    }
    cout << answer;

    return 0;
}