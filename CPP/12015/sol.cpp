#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    int answer = 1;
    vector<int> tmp;
    tmp.push_back(v[0]);
    for(int i = 1;i < N;i++) {
        if(tmp.back() < v[i]) {
            answer++;
            tmp.push_back(v[i]);
        }
        else {
            auto it = lower_bound(tmp.begin(),tmp.end(),v[i]);
            *it = v[i];
        }
    }

    cout << answer;
    return 0;
}

/* helpers */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}