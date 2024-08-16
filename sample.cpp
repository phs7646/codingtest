#include<iostream>
#include<vector>
using namespace std;

int main() {
    int K = 3;
    for(long long N = 1; N <= 100;N++) {
        cout << N << " : ";
        long long left = N*N*N;
        long long right = 0;
        bool r = true;
        long long i = N-1;
        for(;i >= 2;i-=2) {
            if(r) right += i*i*i + (i-1)*(i-1)*(i-1);
            else left += i*i*i + (i-1)*(i-1)*(i-1);
            r = !right;
        }
        if(i==1) {
            if(r) right += 1;
            else left += 1;
        }
        cout << abs(right-left) << endl;
    }
    
    return 0;
}
