#include<iostream>
#include<string>
#include<vector>

#include<climits>
using namespace std;

int main() {
    int H,N;
    cin >> H >> N;
    int dist = max(H,N) - min(H,N);
    if(dist == 0) {
        cout << 1;
        return 0;
    }
    dist++;
    vector<vector<long long>> nums(dist,vector<long long>(dist));
    for(int j = 0;j < dist;j++) nums[0][j] = 1;
    for(int i = 1;i < dist;i++) {
        for(int j = i;j < dist;j++) {
            nums[i][j] = nums[i-1][j] + nums[i][j-1];
        }
    }
    cout << nums[dist-1][dist-1];
    //1 2 5 14
    return 0;
}