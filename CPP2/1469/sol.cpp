#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> v;
vector<int> t;
vector<int> answer;
void dfs(int pos) {
    if(pos == N) {
        bool flag = false;
        if(answer[0] == -1) flag = true;
        else {
            //t가 answer보다 빠른가?
            for(int i = 0;i < 2*N;i++) {
                if(t[i] < answer[i]) {
                    flag = true;
                    break;
                } else if(t[i] > answer[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            answer = t;
        }
    }
    //v[pos]를 어디에 배치할까?
    for(int i = 0;i < 2*N;i++) {
        int left = i;
        int right = i+v[pos]+1;
        if(right < 2*N && t[left] == -1 && t[right] == -1){
            t[left] = v[pos];
            t[right] = v[pos];
            dfs(pos+1);
            t[left] = -1;
            t[right] = -1;
        }
    }
}
int main() {
    cin >> N;
    v.resize(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    sort(v.begin(),v.end());
    t.resize(N*2);
    answer.resize(N*2);
    for(int i = 0;i < 2*N;i++) {
        t[i] = -1;
        answer[i] = -1;
    }
    dfs(0);
    if(answer[0] == -1) cout << -1;
    else {
        for(int n : answer) cout << n << " ";
    }
    return 0;
}