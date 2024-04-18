#include <iostream>
#include <vector>

using namespace std;



int N;
int firstM;
bool compare(const vector<int>& a, const vector<int>& b) {
    if(a.size() != b.size()) return a.size() > b.size();
    bool ret = true;
    for(int i = 0;i < a.size();i++) {
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return false;
}

vector<int> solve(int M, const vector<int>& p, vector<vector<int>>& S) {
    if(!S[M].empty()) return S[M];
    vector<int> max;
    for(int i = N-1;i >= 0;i--) {
        if(i == 0 && firstM == M) continue;
        if(M >= p[i]) { //take i
            vector<int> v;
            v.push_back(i);
            vector<int> v2 = solve(M-p[i], p, S);
            v.insert(v.end(),v2.begin(),v2.end());
            if(compare(v,max)) max = v;
        }
    }
    S[M] = max;
    return max;
}

int main() {
    cin >> N;
    vector<int> p(N);
    for(int i = 0;i < N;i++) cin >> p[i];
    int M;
    cin >> M;
    firstM = M;
    vector<vector<int>> S(M+1);

    vector<int> ans = solve(M,p,S);
    if(ans.size() == 0) cout << 0;
    else for(int i : ans) cout << i;

    return 0;
}