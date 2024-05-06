#include<iostream>
#include<vector>

using namespace std;

/* codes */

int main() {
    int N;
    cin >> N;
    int X,S;
    cin >> X >> S;
    vector<int> c(N);
    vector<int> p(N);
    bool flag = false;
    for(int i = 0;i < N;i++) {
        cin >> c[i] >> p[i];
        if(c[i] <= X && p[i] > S) {
            flag = true;
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}