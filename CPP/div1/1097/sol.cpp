#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPi(const string& b) {
    int m = b.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && b[i] != b[j]) {
            j = pi[j - 1];
        }
        if (b[i] == b[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}
int KMP(const string& a, const string& b) {
    vector<int> pi = getPi(b);
    int n = a.size(), m = b.size(), j = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && a[i] != b[j]) {
            j = pi[j - 1];
        }
        if (a[i] == b[j]) {
            if (j == m - 1) {
                count++;
                j = pi[j];
            } else {
                j++;
            }
        }
    }

    return count;
}

int main() {
    int N,K;
    cin >> N;
    vector<string> v;
    for(int i = 0;i < N;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    cin >> K;

    vector<int> perm(N-1);
    for(int i = 0;i < N-1;i++) perm[i] = i+1;

    int count = 0;
    do {
        string news = v[0];
        for(int index : perm) news.append(v[index]);
        if(KMP(news+news,news)-1 == K) count++;
    } while(next_permutation(perm.begin(),perm.end()));

    cout << count*N;
    return 0;
}