#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    int answer = 1;
    vector<int> tmp;
    vector<int> tmp_idx;
    vector<int> mem(N,-1);
    tmp.push_back(v[0]);
    tmp_idx.push_back(0);
    for(int i = 1;i < N;i++) {
        if(tmp.back() < v[i]) {
            answer++;
            mem[i] = tmp_idx.back();
            tmp.push_back(v[i]);
            tmp_idx.push_back(i);
        }
        else {
            
            auto it = lower_bound(tmp.begin(),tmp.end(),v[i]);
            int index = it - tmp.begin();
            *it = v[i];
            tmp_idx[index] = i;
            if(index > 0) mem[i] = tmp_idx[index-1];
            else mem[i] = -1;
        }
    }

    cout << answer << "\n";

    int index = tmp_idx.back();
    vector<int> lcs;
    while(index != -1) {
        lcs.push_back(v[index]);
        index = mem[index];
    }
    reverse(lcs.begin(),lcs.end());
    vectorprint(lcs);
    return 0;
}

/* helpers */

