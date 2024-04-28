#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];

    int left = 0;
    int right = N-1;
    int answer = INT_MAX;
    int answer_left = 0;
    int answer_right = 0;
    while(left < right) {
        int sum = v[left] + v[right];
        if(abs(sum) < abs(answer)) {
            answer = sum;
            answer_left = left;
            answer_right = right;
        }
        if(sum == 0) break;
        if(sum > 0) right--;
        else left++;
    }

    cout << v[answer_left] << " " << v[answer_right];

    return 0;
}