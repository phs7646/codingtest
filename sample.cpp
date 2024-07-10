#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T; 
    cin >> T;
    for(int t = 0; t < T; t++) {
        vector<int> v(6);
        for(int i = 0; i < 6; i++) cin >> v[i];
        
        int count = 0;
        int left = 0, right = 0;
        
        for(int x = 1; x * v[0] <= v[4] && x * v[1] <= v[5]; ++x) {
            int r1 = v[4] - x * v[0];
            int r2 = v[5] - x * v[1];
            
            if (r1 % v[2] == 0 && r2 % v[3] == 0) {
                int y_legs = r1 / v[2];
                int y_arms = r2 / v[3];
                
                if (y_legs > 0 && y_legs == y_arms) {
                    left = x;
                    right = y_legs;
                    count++;
                }
            }
        }
        
        if (count == 1) {
            cout << left << " " << right << endl;
        } else {
            cout << "?" << endl;
        }
    }
    
    return 0;
}
