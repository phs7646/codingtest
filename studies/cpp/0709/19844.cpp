#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> v = {"c'","j'","m'","t'","s'","l'","d'","qu'"};
    int count = 1;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == ' ' || s[i] == '-') count++;
        for(string c : v) {
            
        }
    }

    return 0;
}