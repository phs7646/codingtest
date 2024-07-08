#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool ispossible(string& a,string& b) {
    int alen = a.size();
    int blen = b.size();
    for(int i = 0;i < blen;i++) {
        //find first character
        if(b[i] != a[0]) continue;
        for(int j = i+1;j < blen;j++) {
            //find second character
            if(b[j] != a[1]) continue;
            //check if remain match
            int dist = j-i;
            bool flag = true;
            int it = j+dist;
            for(int k = 2;k < alen;k++) {
                if(it >= blen || a[k] != b[it]) {
                    flag = false;
                    break;
                }
                it += dist;
            }
            if(flag) return true;
        }
    }    
    return false;
}

int main() {
    int N;
    cin >> N;
    string origin;
    cin >> origin;
    int count = 0;
    for(int n = 0;n < N;n++) {
        string s;
        cin >> s;
        if(ispossible(origin,s)) count++;
    }
    cout << count;
    return 0;
}