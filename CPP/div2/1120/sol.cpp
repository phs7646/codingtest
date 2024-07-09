#include<iostream>
#include<vector>
#include<string>


using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    int diff = b.size()-a.size();
    int m = 0;
    for(int left = 0;left <= diff;left++) {
        int count = 0;
        for(int j = 0;j < a.size();j++) {
            if(a[j] == b[left+j]) count++;
        }
        m = max(m,count);
    }
    cout << b.size() - (m+diff);
    return 0;
}