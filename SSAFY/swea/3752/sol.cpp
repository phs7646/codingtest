#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T; cin >> T;
    int v[100];
    for(int t = 1;t <= T;t++) {
        int N; cin >> N;
        int sum = 0;
        for(int i = 0;i < N;i++) {
            cin >> v[i];
            sum += v[i];
        }
        vector<bool> score(sum+1,false);
        score[0] = true;
        score[v[0]] = true;
        for(int i = 1;i < N;i++) {
            vector<bool> score2(sum+1,false);
            for(int j = 0;j <= sum;j++) {
                if(!score[j]) continue;
                score2[j] = true;
                int k = j+v[i];
                if(k <= sum)score2[k] = true;
            }
            score = score2;
        }
        int count = 0;
        for(int i = 0;i < sum+1;i++) if(score[i]) count++;
        cout << '#' << t << " " << count << "\n";
    }

    return 0;
}