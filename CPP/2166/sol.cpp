#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> X(N+1);
    vector<long long> Y(N+1);
    for(int i = 0;i < N;i++) cin >> X[i] >> Y[i];
    X[N] = X[0];
    Y[N] = Y[0];

    long long sum = 0;
    for(int i = 0;i < N;i++) {
        sum += X[i] * Y[i+1] - X[i+1] * Y[i];
    }
    double answer = static_cast<double>(abs(sum)) / 2;
    cout << fixed << setprecision(1) << answer;
    return 0;
}