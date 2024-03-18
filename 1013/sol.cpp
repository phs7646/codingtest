#include <iostream>
#include <string>

using namespace std;

string s;

bool sat(int pos) {
    if(pos == s.length()) return true;
    if(pos+1 == s.length()) return false;
    char a = s[pos];
    char b = s[pos+1];
    if(a == b) return false;
    if(a == '0' && b == '1') {
        return sat(pos+2);
    } else {
        int new_pos = pos+2;
        if(s[new_pos] != '0') return false;
        //consume all 0
        while(new_pos < s.length() && s[new_pos] == '0') new_pos++;
        if(new_pos == s.length()) return false;
        //consume all 1
        while(new_pos < s.length() && s[new_pos] == '1') new_pos++;
        if(new_pos == s.length()) return true;
        if(s[new_pos-2] == '1' && sat(new_pos-1)) return true;
        return sat(new_pos);
    }
}

int main() {
    int T;
    char trash;
    cin >> T >> trash;
    for(int t = 0;t < T;t++) {
        getline(cin,s);
        if(s.length() <= 1) {
            cout << "NO\n";
            continue;
        }
        int pos = 0;
        if(sat(0)) cout << "YES\n";
        else cout << "NO\n";
    }
}