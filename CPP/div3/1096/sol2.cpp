#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -101;

void fold_and_unfold(vector<vector<int>>& v, int start_row, int start_col, int end_row, int end_col) {
    int N = end_row - start_row;
    int M = end_col - start_col;

    if (N == 1 && M == 1) {
        return;
    }

    for (int i = 1; i < N; i++) {
        vector<vector<int>> original = v;
        // 상단과 하단을 접기
        for (int j = start_col; j < end_col; j++) {
            for (int k = 0; k < i; k++) {
                v[end_row - i + k][j] += v[start_row + i - k - 1][j];
                answer = max(answer, v[end_row - i + k][j]);
            }
        }
        fold_and_unfold(v, start_row + i, start_col, end_row, end_col);
        v = original;  // 원상 복구
    }

    for (int j = 1; j < M; j++) {
        vector<vector<int>> original = v;
        // 좌측과 우측을 접기
        for (int i = start_row; i < end_row; i++) {
            for (int k = 0; k < j; k++) {
                v[i][end_col - j + k] += v[i][start_col + j - k - 1];
                answer = max(answer, v[i][end_col - j + k]);
            }
        }
        fold_and_unfold(v, start_row, start_col + j, end_row, end_col);
        v = original;  // 원상 복구
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> paper(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
            answer = max(answer, paper[i][j]);
        }
    }

    fold_and_unfold(paper, 0, 0, N, M);
    cout << answer << endl;

    return 0;
}
