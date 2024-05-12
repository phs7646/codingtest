#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void recur(string& s,int k,int pos) {
    if(k == 0) return;
    //pos ~ pos + k : recur
    recur(s,k/3,pos);
    //pos + k ~ pos + 2k : remove
    for(int i = pos+k;i < pos+2*k;i++) s[i] = ' '; 
    //pos + 2k ~ end : recur
    recur(s,k/3,pos+2*k);
}


int main() {
    int N;
    while(cin >> N) {
        string s = " ";
        int length = static_cast<int>(pow(3,N));
        for(int i = 0;i < length;i++) s.push_back('-');
        recur(s,length/3,1);
        cout<<s.substr(1)<<endl;
    }
    return 0;
}