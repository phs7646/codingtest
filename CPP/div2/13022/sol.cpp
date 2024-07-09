#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag = true;
    for(auto it = s.begin();it < s.end();) {
        if(*it == 'w') {
            //consume all w
            int n = 1;
            it++;
            while(it < s.end() && *it == 'w') {it++;n++;}
            if(it == s.end()) {
                flag = false;
                break;
            }
            //cout << "will consume " << n << endl;
            //consume o 
            for(int i = 0;i < n;i++) {
                if(it >= s.end() || *it != 'o') {
                    flag = false;
                    break;
                }
                it++;
            }
            //consume l
            for(int i = 0;i < n;i++) {
                if(it >= s.end() || *it != 'l') {
                    flag = false;
                    break;
                }
                it++;
            }
            //consume f
            for(int i = 0;i < n;i++) {
                if(it >= s.end() || *it != 'f') {
                    flag = false;
                    break;
                }
                it++;
            }
            //cout << "after consume, *it is " << *it << endl;
        } else {
            flag = false;
            break;
        }
    }
    if(flag) cout << 1;
    else cout << 0;
    return 0;
}