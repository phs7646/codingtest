#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include<string.h>

using namespace std;


int main() {
    string a,b;
    while(getline(cin,a)) {
        getline(cin,b);
        vector<bool> used(1001);
        string answer = "";
        for(int j = 0;a[j] != '\0';j++) {
            for(int i = 0;b[i] != '\0';i++) {
                if(!used[i] && a[j] == b[i]) {
                    used[i] = true;
                    answer.push_back(a[j]);
                    break;
                } 
            }
        }
        sort(answer.begin(),answer.end());
        cout << answer << endl;
    }
    return 0;
}