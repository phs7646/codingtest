#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> length(35, 0);
string init, temp;

char search(int times, long long pos) {
    if (times == 0) return init[pos];
    long long len = length[times - 1];
    long long left = 0;
    for (int i = 0; i < temp.size(); i++) {
        long long right = left;
        if (temp[i] == '$') right += len;
        else right += 1;
        if (left <= pos && pos < right) { // 수정: pos <= right
            if (temp[i] != '$') return temp[i];
            return search(times - 1, pos - left);
        }
        left = right;
    }
    return '-';
}

int main() {
    cin >> init;
    cin >> temp;
    int times;
    long long start, end;
    cin >> times >> start >> end;
    start--;
    end--;
    int A = 0, B = 0;
    for (char c : temp) {
        if (c == '$') A++;
        else B++;
    }
    string answer;
    if (A == 1) {
        string init2 = temp.substr(1, temp.size() - 1);
        long long realend = init.size() + times * B - 1;
        realend = min(realend, end);
        for (long long i = start; i <= realend; i++) {
            if (i < init.size()) answer.push_back(init[i]);
            else {
                long long pos = i - init.size();
                answer.push_back(init2[pos % init2.size()]);
            }
        }
    } else {
        length[0] = init.size();
        int realtimes = 1;
        for (; realtimes < 35; realtimes++) {
            length[realtimes] = A * length[realtimes - 1] + B;
            if (length[realtimes] > end) break;
        }

        for (long long i = start; i <= end; i++) answer.push_back(search(realtimes, i));
    }
    while (answer.size() < end - start + 1) answer.push_back('-');
    cout << answer;
    return 0;
}
