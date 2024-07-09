#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    int left = 0,right=INT_MIN;
    long long sum = 0;
    for(int i = 0;i < N;i++) {
        cin >> v[i];
        right = max(right,v[i]);
        sum += v[i];
    }
    long long M;
    cin >> M;
    if(sum <= M) {
        cout << right;
        return 0;
    }
    while(left < right) {
        int mid = (left+right)/2;
        long long sum = 0;
        for(int n : v) {
            if(n > mid) sum += mid;
            else sum += n;
        }
        //cout << "left : " << left << " right : " << right << " sum : " << sum << endl;
        if(sum > M) right = mid-1;
        else {
            if(left == mid) break;
            else left = mid;
        }
    }
    if(left != right) {
        long long sum = 0;
        for(int n : v) {
            if(n > right) sum += right;
            else sum += n;
        }
        if(sum <= M) cout << right;
        else cout << left;
    } else cout << left;

    return 0;
}