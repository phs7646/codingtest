#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> v;
    vector<int> v2;
    for(int i = 0;i < N;i++) {
        int a;
        cin >> a;
        if(a%10 == 0) v.push_back(a);
        else v2.push_back(a);
    }
    int answer = 0;
    sort(v.begin(),v.end());
    for(int n : v) {
        while(n>0) { 
            if(n == 10) {
                answer++;
                break;
            } else if(M == 0 || n < 10) {
                break;
            } else {
                n -= 10;
                M -= 1;
                answer++;
            }
        }
    }
    for(int n : v2) {
        while(n>0) {
            if(n == 10) {
                answer++;
                break;
            } else if(M == 0 || n < 10) {
                break;
            } else {
                n -= 10;
                M -= 1;
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}