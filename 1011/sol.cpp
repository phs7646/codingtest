#include <iostream>
#include <math.h>

using namespace std;
int memo[1000];
int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        int X,Y,dist;
        cin >> X >> Y;
        dist = Y-X;
        //dist = t;
        if(dist == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        int k = sqrt(dist);
        int ans = 0;
        if(k * k == dist) ans = 2*k-1;
        else if(k * (k+1) >= dist) ans = 2*k;
        else ans = 2*k+1;
        //cout << k << " " << ans << "\n"; 
        cout << ans << "\n"; 
    }
}