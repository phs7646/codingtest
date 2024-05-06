#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> h;

    for (int i = 1; i <= M; i++) {
        int h1, h2;
        cin >> h1 >> h2;
        h.push_back({h1, i}); 
        h.push_back({h2, i});
    }

    sort(h.begin(), h.end());

    cout << h[(N-1) % (2*M)].second;
    return 0;
}
