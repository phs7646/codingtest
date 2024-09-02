#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int N;
int rootN;

class Query {
public:
    int L, R, index;
    Query(int a, int b, int c) : L(a), R(b), index(c) {}
    bool operator <(const Query& q2) {
        int l = L / rootN;
        int r = q2.L / rootN;
        if (l != r) return l < r;
        else return (l % 2 == 0) ? (R < q2.R) : (R > q2.R);
    }
};

int arr[100000];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    rootN = sqrt(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<Query> queries;
    int M; cin >> M;
    for (int m = 0; m < M; m++) {
        int a, b; cin >> a >> b;
        queries.emplace_back(a - 1, b - 1, m);
    }
    sort(queries.begin(), queries.end());
    vector<int> answer(M);

    // 첫 번째 쿼리 처리
    int numCount = 0;
    unordered_map<int, int> counter;
    Query q1 = queries[0];
    for (int i = q1.L; i <= q1.R; i++) {
        if (++counter[arr[i]] == 1) numCount++;
    }
    answer[q1.index] = numCount;

    // 나머지 쿼리 처리
    int curL = q1.L;
    int curR = q1.R;
    for (int i = 1; i < M; i++) {
        Query q = queries[i];
        
        while (curL < q.L) {
            if (--counter[arr[curL]] == 0) numCount--;
            curL++;
        }
        while (curL > q.L) {
            curL--;
            if (++counter[arr[curL]] == 1) numCount++;
        }
        
        while (curR < q.R) {
            curR++;
            if (++counter[arr[curR]] == 1) numCount++;
        }
        while (curR > q.R) {
            if (--counter[arr[curR]] == 0) numCount--;
            curR--;
        }
        answer[q.index] = numCount;
    }

    for (int ans : answer) cout << ans << "\n";
    return 0;
}
