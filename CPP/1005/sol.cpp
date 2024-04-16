#include  <iostream>
#include <vector>

using namespace std;
vector<int> rule[1000];
int D[1000];
int C[1000];

int min(int W) {
    if(C[W] != -1) return C[W];
    if(rule[W].size() == 0) {
        C[W] = D[W];
        return D[W];
    }
    int maxtime = min(rule[W].at(0));
    for(int i = 1;i < rule[W].size();i++) {
        int t = min(rule[W].at(i));
        if(t > maxtime) maxtime = t;
    }
    C[W] = maxtime + D[W];
    return C[W];
}
int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        //testcase t
        //input
        int N,K;
        cin >> N >> K;

        for(int i = 0;i < N;i++) {
            cin >> D[i];
            rule[i].clear();
        }
        for(int i = 0;i < K;i++) {
            int tmp1,tmp2;
            cin >> tmp1 >> tmp2;
            rule[tmp2-1].push_back(tmp1-1);
        }
        for(int i = 0;i < N;i++) {
            C[i] = -1;
        }

        int W;
        cin >> W;
        cout << min(W-1) << "\n";
    }
}