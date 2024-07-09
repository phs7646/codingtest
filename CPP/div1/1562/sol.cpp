#include <iostream>
#include <vector>

using namespace std;

int myadd(int a,int b) {
    long long value = 0;
    value += static_cast<long long>(a);
    value += static_cast<long long>(b);
    value %= 1000000000;
    return static_cast<int>(value);
}

int main() {
    int N;
    cin >> N;

    vector<vector<vector<int>>> v(N+1, vector<vector<int>>(10, vector<int>(4, 0))); // N , X , bit. bit = 0,1,2,3 
    //bit 0 : nohit, 1 : hit 0, 2 : hit 9 , 3 : hit both

    v[1][9][2] = 1;

    for(int x = 1;x <= 8;x++) {
        v[1][x][0] = 1;
    } 

    for(int n = 2; n <= N;n++) {
        v[n][0][0] = 0;
        v[n][0][1] = myadd(v[n-1][1][0],v[n-1][1][1]);
        v[n][0][2] = 0;
        v[n][0][3] = myadd(v[n-1][1][2],v[n-1][1][3]);

        v[n][9][0] = 0;
        v[n][9][1] = 0;
        v[n][9][2] = myadd(v[n-1][8][0],v[n-1][8][2]);
        v[n][9][3] = myadd(v[n-1][8][1],v[n-1][8][3]);

        for(int x = 1; x <= 8;x++) {
            for(int bit = 0;bit < 4;bit++) {
                v[n][x][bit] = myadd(v[n-1][x-1][bit], v[n-1][x+1][bit]);
            }
        }
    }

    long long answer = 0;
    for(int x = 0; x < 10;x ++) {
        answer = (answer + v[N][x][3])%1000000000;
    }
    cout << answer;
    return 0;
}