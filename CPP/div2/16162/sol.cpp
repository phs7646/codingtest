#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N,A,D;
    cin >> N >> A >> D;
    vector<int> v;
    for(int i = 0;i < N;i++) {
        int t;
        cin >> t;
        if((t-A)%D == 0) v.push_back(t);
    }
    N = v.size();
    int answer = 0;
    vector<int> d(N);
    for(int i = N-1;i >= 0;i--) {
        //find next
        int j = i+1;
        while(j < N) {
            if(v[j] - v[i] == D) {
                break;
            }
            j++;
        }
        if(j >= N) d[i] = 1;
        else d[i] = d[j] + 1;
        if(v[i] == A) answer = max(answer,d[i]);
    }
    cout << answer;
    return 0;

}