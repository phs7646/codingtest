#include<iostream>
#include<vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    vector<int> v(Q);
    for(int i = 0;i < Q;i++) cin >> v[i];
    vector<bool> visited(N);
    for(int target : v) {
        //target에서 시작해서 루트까지 트래블하면서 만나는 노드 적립
        int met = 0;
        int cur = target;
        while(cur >= 1) {
            if(visited[cur]) {
                met = cur;
            }
            cur /= 2;
        }
        if(met == 0) visited[target] = true;
        cout << met << "\n";
    }
    return 0;
}