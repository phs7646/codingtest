#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long two_chunk_cost(int x, int y) {
    return static_cast<long long>(x) * y;
}

long long three_chunk_cost(int x, int y, int z) {
    return static_cast<long long>(x) * y + static_cast<long long>(y) * z + static_cast<long long>(z) * x;
}

int main() {
    int N = 10, A = 1, B = 10;
    long long min_cost = LLONG_MAX;

    // 두 덩어리로 나누는 경우
    for (int i = A; i <= B; ++i) {
        if (N - i >= A && N - i <= B) {
            min_cost = min(min_cost, two_chunk_cost(i, N - i));
        }
    }

    // 세 덩어리로 나누는 경우
    for (int i = A; i <= B; ++i) {
        for (int j = A; j <= B; ++j) {
            if (N - i - j >= A && N - i - j <= B) {
                min_cost = min(min_cost, three_chunk_cost(i, j, N - i - j));
            }
        }
    }

    cout << "Minimum cost: " << min_cost << endl;
    return 0;
}
