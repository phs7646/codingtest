#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<string> lib(10);
    lib[0] = "**** ** ** ****";
    lib[1] = "  *  *  *  *  *";
    lib[2] = "***  *****  ***";
    lib[3] = "***  ****  ****";
    lib[4] = "* ** ****  *  *";
    lib[5] = "****  ***  ****";
    lib[6] = "****  **** ****";
    lib[7] = "***  *  *  *  *";
    lib[8] = "**** ***** ****";
    lib[9] = "**** ****  ****";
    vector<string> v(5);
    for(int i = 0;i < 5;i++)getline(cin,v[i]);
    int len = v[0].size();
    int parsed = 0;
    for(int i = 0;i < len;) {
        //try match i,i+1,i+2
        bool success = false;
        int digit = 0;
        for(;digit <= 9;digit++) {
            //match digit
            bool match = true;
            for(int a = 0;a < 5;a++) {
                for(int b = 0;b < 3;b++) {
                    if(lib[digit][a*3+b] != v[a][i+b]) {
                        match = false;
                        break;
                    }
                }
                if(!match) break;
            }
            if(match) {
                success = true;
                break;
            }
        }
        if(success) {
            parsed = parsed*10 + digit;
            i+=4;
        } else {
            parsed = -1;
            break;
        }
    }
    if(parsed % 6 == 0) cout << "BEER!!";
    else cout << "BOOM!!";
    return 0;
}