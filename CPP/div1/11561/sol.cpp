#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        long long N;
        cin >> N;
        if(N==1) {
            cout << 1 << "\n";
            continue;
        } 
        //1..k -> (k)(k+1)/2
        long long k = static_cast<long long>(round(sqrt(2*N)));
        long long val = k * (k + 1) / 2;
        while(val > N) {
            val -= k;
            k--;
        }
        //cout<<k << " " <<val << "\n";
        while( N-val > k+1) {
            k++;
            val += k;
        }
        cout << k << "\n";
    }
    return 0;
}