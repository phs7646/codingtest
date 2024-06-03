#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string a;
    cin >> a;
    char cur = a[0];
    int count = 1;
    int left = 0;
    int right = N-1;
    while(left < N && a[left] == cur) left++;
    while(right >= 0 && a[right] == cur) right--;
    //cur로 모두 색칠한 상태
    while(left <= right) {
        cur = a[left];
        count++;
        //cout << cur << " 로 색칠 : " << left << " , " << right << "\n";
        while(left < N && a[left] == cur) left++;
        while(right >= 0 && a[right] == cur) right--;
    }
    cout << count;
    return 0;
}