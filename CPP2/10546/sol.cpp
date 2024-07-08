#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> v;
    vector<string> v2;
    for(int i = 0;i < N;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(int i = 0;i < N-1;i++) {
        string s;
        cin >> s;
        v2.push_back(s);
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    for(int i = 0;i < N;i++) {
        if(i == N-1 || v[i] != v2[i]) {
            cout << v[i];
            return 0;
        }
    }
    return 0;
}