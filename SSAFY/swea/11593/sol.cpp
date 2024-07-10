#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

long long fact[21];

long long findOrder(string s) {
    int N = s.size();
    long long order = 0;

    vector<char> sorted(N);
    for(int i = 0;i < N;i++) sorted[i] = s[i];
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < N; ++i) {
        map<char,int> count;
        for(char c : sorted) count[c]++;
        auto it = find(sorted.begin(), sorted.end(), s[i]);
        int idx = it - sorted.begin();
        long long addorder = idx * fact[N-1 - i];
        for(auto pair : count) {
            if(pair.second > 1) addorder /= fact[pair.second];
        }
        order += addorder;
        sorted.erase(it);
    }

    return order;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2;i < 21;i++) fact[i] = fact[i-1] * i; 
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        string s; cin >> s;
        cout << '#' << t << " " << findOrder(s) << "\n";
    }
}
