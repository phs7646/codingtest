#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAXNODE 100000
int N, M;
int root[MAXNODE];
int diff[MAXNODE];
int countN[MAXNODE];

pair<int, int> findRoot(int n) {
    if (root[n] != n) {
        pair<int, int> r = findRoot(root[n]);
        root[n] = r.first;
        diff[n] += r.second;
    }
    return {root[n], diff[n]};
}

void insert(int a, int b, int d) {
    pair<int, int> reta = findRoot(a);
    pair<int, int> retb = findRoot(b);
    int roota = reta.first;
    int rootb = retb.first;
    int diffa = reta.second;
    int diffb = retb.second;

    if (roota != rootb) {
        if (countN[roota] > countN[rootb]) {
            root[rootb] = roota;
            diff[rootb] = diffa + d - diffb;
        } else if (countN[roota] < countN[rootb]) {
            root[roota] = rootb;
            diff[roota] = diffb - d - diffa;
        } else {
            root[rootb] = roota;
            diff[rootb] = diffa + d - diffb;
            countN[roota]++;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    while (!(N==0 && M==0)) {
        for (int i = 1; i <= N; ++i) {
            root[i] = i;
            diff[i] = 0;
            countN[i] = 0;
        }

        for (int m = 0; m < M; m++) {
            char c; cin >> c;
            if (c == '!') {
                int a, b, d; cin >> a >> b >> d;
                insert(a, b, d);
            } else {
                int a, b; cin >> a >> b;
                pair<int, int> reta = findRoot(a);
                pair<int, int> retb = findRoot(b);
                if (reta.first != retb.first) {
                    cout << "UNKNOWN\n";
                } else {
                    cout << retb.second - reta.second << "\n";
                }
            }
        }
        cin >> N >> M;
    }
    return 0;
}
