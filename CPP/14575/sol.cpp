#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N,T;
    cin >> N >> T;
    int sumL = 0;
    int sumR = 0;
    int maxL = 0;
    int maxR = 0;
    vector<int> L(N);
    vector<int> R(N);
    for(int i = 0;i < N;i++) {
        cin >> L[i] >> R[i];
        sumL += L[i];
        sumR += R[i];
        maxL = max(maxL,L[i]);
        maxR = max(maxR,R[i]);
    }
    if(T < sumL || sumR < T) {
        cout << -1;
        return 0;
    }
    int left = maxL;
    int right = maxR;

    while(left < right) {
        int mid = (left+right)/2;
        //S를 mid로 정하면?
        int sum = 0;
        for(int i = 0;i < N;i++) sum += min(R[i],mid);
        if(sum >= T) {
            //possible -> 왼쪽구간
            right = mid;
        } else {
            //impossible -> 오른쪽구간
            left = mid+1;
        }
    }
    cout << left;
    return 0;
}