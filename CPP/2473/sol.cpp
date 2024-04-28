#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    sort(v.begin(),v.end());
    
    vector<int> answer_index;
    long long answer = LLONG_MAX;
    
    for(int i = 0;i < N-2;i++) {
        long long fixed = v[i];
        int left = i+1;
        int right = N-1;

        while(left < right) {
            long long sum = fixed + static_cast<long long>(v[left]) + static_cast<long long>(v[right]);
            if(abs(sum) < abs(answer)) {
                answer = sum;
                answer_index = {i,left,right};
            }
            if(sum == 0) break;
            if(sum > 0) right--;
            else left++;
        }
        if(answer == 0) break;
    }

    for(int n : answer_index) cout << v[n] << " ";
    return 0;
}