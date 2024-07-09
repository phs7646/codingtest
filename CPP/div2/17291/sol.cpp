#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N+5);
    v[1] = 1;
    for(int i = 1;i <= N;i++) {
        if(i%2 == 0) {
            for(int j = i-4;j < i;j++) {
                if(j >= 0) v[i] += v[j];
            }
        } else {
            for(int j = i-3;j < i;j++) {
                if(j >= 0) v[i] += v[j];
            }
        }
    }
    int answer = 0;
    if(N%2 == 0) {
        for(int j = N-2;j <= N;j++) {
            if(j >= 0) answer += v[j];
        }
    } else {
        for(int j = N-3;j <= N;j++) {
            if(j >= 0) answer += v[j];
        }
    }
    cout << answer;
    return 0;
}