#include<iostream>
#include<vector>

using namespace std;



int main() {
    int N;
    cin >> N;
    vector<long long> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    if(N==1) {
        cout << v[0];
        return 0;
    }
    long long speed = v[N-1];
    for(int i = N-2;i >= 0;i--) {
        if(speed <= v[i]) speed = v[i];
        else if(speed % v[i] != 0) {
            speed = (1 + speed / v[i]) * v[i];
        }
    }
    cout << speed;
    return 0;
}