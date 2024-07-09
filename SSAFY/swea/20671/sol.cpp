#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
long long mod = 1000000007;
int N;
pair<string, int> arr[200];
int tag[200];
long long answer;
long long cur;
 
string getInput() {
    string s;
    cin >> s;
    return s;
}
 
long long stringToModInt(const string &s) {
    long long ret = 0;
    for (char digit : s) {
        ret = (ret * 10 + (digit - '0')) % mod;
    }
    return ret;
}
 
void accum(const string &s) {
    for (char digit : s) {
        cur = (cur * 10 + (digit - '0')) % mod;
    }
}
 
void dfs(int pos) {
    if (pos >= 2 * N) {
        answer = (answer + cur) % mod;
        return;
    }
    if (tag[pos] == 1) {
        dfs(pos + 1);
        return;
    }
    if (tag[pos] == 2) {
        long long sav = cur;
        accum(arr[pos].first);
        dfs(pos + 1);
        cur = sav;
        return;
    }
    long long sav = cur;
    accum(arr[pos].first);
    int i = pos + 1;
    for (; i < 2 * N; i++) {
        if (arr[i].second == arr[pos].second) {
            tag[i] = 1;
            break;
        }
    }
    dfs(pos + 1);
    cur = sav;
    tag[i] = 2;
    dfs(pos + 1);
    tag[i] = 0;
}
 
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<pair<string, int>> a(2 * N);
        for (int i = 0; i < N; i++) {
            a[2 * i].first = getInput();
            a[2 * i].second = i;
            a[2 * i + 1].first = getInput();
            a[2 * i + 1].second = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < 2 * N; i++) arr[i] = a[i];
        answer = 0;
        cur = 0;
        fill(tag, tag + 2 * N, 0);
        dfs(0);
        cout << '#' << t << " " << answer << "\n";
    }
}