#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int R,C;
    cin >> R >> C;
    vector<vector<int>> v(R,vector<int>(C));
    for(int i = 0;i < R;i++) {
        for(int j = 0;j < C;j++) {
            char c;
            cin >> c;
            v[i][j] = c-'a';
        }
    }
    int left = 0;
    int right = R-1;
    int result = 0;
    while(left <= right) {
        int mid = (left+right)/2;
        bool flag = true;
        //mid까지 봤을 때 중복 문자열 존재?
        //mid .. R
        vector<vector<int>> tmp(C,vector<int>(R-mid));
        for(int i = 0;i < C;i++) {
            for(int j = mid;j < R;j++) {
                tmp[i][j-mid] = v[j][i];
            }
        }
        sort(tmp.begin(),tmp.end());
        for(int i = 0;i < C-1;i++) {
            //tmp[i] 와 tmp[i+1]이 같은지 확인
            bool b = true;
            for(int j = 0;j < R-mid;j++) {
                if(tmp[i][j] != tmp[i+1][j]) {
                    b = false;
                    break;
                }
            }
            if(b) {
                flag = false;
                break;
            }
        }
        //cout << left << "and" << right << " is " << flag << endl;
        if(flag) {
            result = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    cout << result;
    return 0;
}