#include<iostream>
#include<vector>
#include<set>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0;i < N;i++) cin >> arr[i];
    set<int> values;

    int max_bit = 1 << N; // 11..11 -> case
    for(int bit = 1;bit < max_bit;bit++) {
        int sum = 0;
        for(int i = 0;i < N;i++) {
            if(bit & (1<<i)) sum += arr[i];
        }
        values.insert(sum);
    }

    int answer = 1;
    auto it = values.begin();
    while(true) {
        if(answer == *it) {
            answer++;
            it = next(it);
        } else break;
    }
    cout << answer;
    return 0;
}