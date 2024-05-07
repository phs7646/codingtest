#include<iostream>
#include<vector>
#include<set>

using namespace std;

/* helper functions */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}

template<typename T>
vector<T> vectorinput(int n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

/* codes */

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        int K;
        cin >> K;
        multiset<int> ms;
        for(int k = 0;k < K;k++) {
            char c;
            int value;
            cin >> c >> value;
            if(c == 'I') ms.insert(value);
            else if(!ms.empty()){
                if(value == 1) {
                    ms.erase(prev(ms.end()));
                } else {
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *(prev(ms.end())) << " " << *ms.begin() << "\n";
    }
    return 0;
}