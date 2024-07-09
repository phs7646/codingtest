#include<iostream>
#include<vector>
#include<string>
using namespace std;

char toLower(char c) {
    if(c <= 'Z') return c + 32;
    else return c; 
}

int main() {
    string a;
    getline(cin,a);
    int space;
    cin >> space;
    vector<int> remain(26);
    for(int i = 0;i < 26;i++) cin >> remain[i];

    char prev = '\0';
    string answer = "";
    for(char c : a) {
        if(c == ' ') {
            if(prev == ' ') continue;
            if(space == 0) {
                cout << -1;
                return 0;
            }
            space--;
            prev = c;
        } else if(prev == c) {
            continue;
        } else {
            int ord = toLower(c)-'a';
            if(remain[ord] == 0) {
                cout << -1;
                return 0;
            }
            remain[ord]--;
            if(prev == ' ' || prev == '\0')answer.push_back('A'+ord);
            prev = c;
        }
    }
    prev = '\0';
    for(char c : answer) {
        if(c == prev) continue;
        if(remain[c-'A'] == 0) {
            cout << -1;
            return 0;
        }
        remain[c-'A']--;
        prev = c;
    }
    cout << answer;
    return 0;
}