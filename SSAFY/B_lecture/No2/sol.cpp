#include<iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        int N,M; cin >> N >> M;
        int bit = (1<<N)-1;
        cout << '#' << t << ' ';
        if((M&bit) == bit) {
            cout << "ON\n";
        } else cout << "OFF\n";
    }
    return 0;
}