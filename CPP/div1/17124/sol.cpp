#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        int N,M;
        cin >> N >> M;
        vector<int> A(N);
        vector<int> B(M);
        for(int i = 0;i < N;i++) cin >> A[i];
        for(int j = 0;j < M;j++) cin >> B[j];
        sort(B.begin(),B.end());
        long long sum = 0;
        for(int i = 0;i < N;i++) {
            auto ptr = lower_bound(B.begin(),B.end(),A[i]);
            if(ptr == B.end()) sum += *prev(B.end());
            else if(ptr == B.begin()) sum += *(B.begin());
            else {
                int left = *prev(ptr);
                int right = *ptr;
                if(abs(left - A[i]) <= abs(right - A[i])) sum += left;
                else sum += right;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}