#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<int> power(N);
    vector<string> name(N);;
    for(int i = 0;i < N;i++) cin >> name[i] >> power[i];
    for(int i = 0;i < M;i++) {
        int tar;
        cin >> tar;
        auto find = lower_bound(power.begin(),power.end(),tar);
        cout << name[find-power.begin()]<<"\n";
    }
    return 0;
}