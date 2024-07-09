#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num(char a) {
    if('a' <= a && a <= 'z') return a - 'a';
    else return a - 'A';
}

int next(string& a, int pos) {
    while(pos < a.size() && a[pos] != ' ') pos++;
    return pos+1;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    vector<string> lines;
    for(int i = 0;i < N;i++) {
        string s;
        getline(cin,s);
        lines.push_back(s);
    }
    vector<bool> used(N);
    vector<int> answer(N,-1);


    for(int i = 0;i < N;i++) {
        int cursor = 0;
        int length = lines[i].size();

        //각 단어의 앞 글자 탐색
        do {
            if(used[num(lines[i][cursor])] == false) {
                answer[i] = cursor;
                used[num(lines[i][cursor])] = true;
                break;
            }
            cursor = next(lines[i],cursor);
        } while(cursor < length);

        //앞 글자가 모두 사용중이면 전체 탐색
        if(answer[i] == -1) {
            for(int j = 1;j < length;j++) {
                if(lines[i][j] == ' ') continue;
                if(used[num(lines[i][j])] == false) {
                    answer[i] = j;
                    used[num(lines[i][j])] = true;
                    break;
                }
            }
        }
    }

    for(int i = 0;i < N;i++) {
        if(answer[i] == -1) {
            cout << lines[i] << "\n";
            continue;
        }
        int j = 0;
        for(;j < answer[i];j++) cout << lines[i][j];
        cout << '[' << lines[i][j] << ']';
        j++;
        for(;j < lines[i].size();j++) cout << lines[i][j];
        cout << "\n";
    }

    return 0;
}