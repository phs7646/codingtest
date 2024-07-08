#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    vector<bool> visited(N);
    for(int stair = 0;stair < N;stair++) {
        vector<pair<string,int>> tmp;
        for(int i = 0;i < N;i++) {
            if(visited[i] == 0) {
                //build string visited + i
                string t;
                for(int j = 0;j < N;j++) {
                    if(j == i || visited[j]) t.push_back(s[j]);
                }
                tmp.push_back({t,i});
            }
        }
        sort(tmp.begin(),tmp.end());
        cout << tmp[0].first << "\n";
        visited[tmp[0].second] = true;
    }
    return 0;
}