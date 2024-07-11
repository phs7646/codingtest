#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int N;cin >> N;
    vector<long long> A(N+1);
    for(int i = 0;i < N;i++) cin >> A[i+1];
    vector<long long> minK(N+1,LLONG_MAX);
    minK[1] = 0;
    for(int i = 1;i < N;i++) {
        for(int j = i+1;j <= N;j++) {
            //i to j jump!
            long long cost = (j-i) * (1 + abs(A[i]-A[j]));
            minK[j] = min(minK[j],max(minK[i],cost));
        }
    }
    cout << minK[N];
    return 0;
}