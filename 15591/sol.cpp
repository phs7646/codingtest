#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> U[5000];

int sol(int last, int now, int k) {
    int ret = 1;
    for(pair<int,int> p : U[now]) {
        if(p.first == last) continue;
        if(p.second < k) continue;
        ret += sol(now,p.first,k);
    }
    return ret;
}

int main() {
    int N,Q;
    cin >> N >> Q;
    for(int i = 0;i < N-1;i++) {
        int a,b,r;
        cin >> a >> b >> r;
        U[a-1].push_back(make_pair(b-1,r));
        U[b-1].push_back(make_pair(a-1,r));
    }
    for(int t = 0;t < Q;t++) {
        int k,v;
        cin >> k >> v;
        cout << sol(-1,v-1,k)-1 << "\n";
    }
}