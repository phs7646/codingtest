#include<iostream>
#include<vector>
#include<string>
using namespace std;

int tenof(int n) {
    if(n == 0) return 1;
    if(n == 1) return 10;
    return tenof(n/2) * tenof(n - n/2);
}

int main() {
    while(true) {
        string s;
        cin >> s;
        if(s.size() == 1 && s[0] == '0') break;
        int count = 0;
        int value = 0;
        int len = s.size();
        for(char c : s) {
            value = 10 * value + (c - '0');
        }
        while(true) {
            //check if pelindrome in length len
            bool flag = true;
            for(int i = 0;i <= len/2;i++) {
                //i번째와 len-i번째가 같은가?
                if((value / tenof(i))%10 != (value / tenof(len-i-1))%10) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
            //+1
            value++;
            count++;
        }
        cout << count << "\n";
    }
    return 0;
}