#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<string> words(N);
    int sum_len = 0;
    for(int i = 0;i < N;i++) {
        cin >> words[i];
        sum_len += words[i].size();
    }

    int lower = (M-sum_len)/(N-1);
    int upper = lower+1;
    int lower_num = (N-1) - ((M-sum_len) - (lower * (N-1)));
    int upper_num = N-1-lower_num;

    int lower_count = 0;
    int upper_count = 0;

    cout << words[0];
    for(int i = 1;i < N;i++) {
        //next word is lowercase or used all lower count
        if(upper_count < upper_num && (lower_count >= lower_num || 'a'<=words[i][0])) {
            //use upper_count
            upper_count++;
            for(int j = 0;j < upper;j++) cout << "_";
        } else {
            //use lower_count
            lower_count++;
            for(int j = 0;j < lower;j++) cout << "_";
        }
        cout << words[i];
    }

    return 0;
}