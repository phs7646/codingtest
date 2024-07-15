#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T;cin >> T;
    for(int t = 1;t <= T;t++) {
        int N; cin >> N;
        vector<int> v(N);
        for(int i = 0;i < N;i++) cin >> v[i];
        vector<int> lis = {v[0]};
        for(int i = 1;i < N;i++) {
            auto it = lower_bound(lis.begin(),lis.end(),v[i]);
            if(it == lis.end()) lis.push_back(v[i]);
            else *it = v[i];
            //for(int n : lis) cout << n << " ";
            //cout << endl; 
        }
        cout << '#' << t << " " << N-lis.size() << "\n";
    }

    return 0;
}