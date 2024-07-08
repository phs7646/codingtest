#include<iostream>
#include<vector>

using namespace std;
int N,M;
vector<vector<int>> interest(15,vector<int>(4));
vector<pair<int,int>> prefer(15);
int main() {
    //input
    cin >> N >> M;
    for(int i = 0;i < N;i++) for(int j = 0;j < 4;j++) cin >> interest[i][j];
    for(int i = 0;i < N;i++) {
        int a,b;
        cin >> a >> b;
        prefer[i] = {a-1,b-1};
    }
    vector<vector<int>> edges(M);
    for(int i = 0;i < M;i++) {
        int A,B,T;
        cin >> A >> B >> T;
        edges[i].push_back(A-1);
        edges[i].push_back(B-1);
        edges[i].push_back(T-1);
    }
    //solve
    long long max_bit = 1 << N; //0 : first_prefer, 1 : second_prefer
    for(long long bit = 0;bit < max_bit;bit++) {
        //place frogs
        vector<int> place(N,-1);
        for(int i = 0;i < N;i++) {
            int where = -1;
            if((bit & (1<<i)) == 0) {
                //first_prefer
                where = prefer[i].first;
            } else {
                //second_prefer
                if(prefer[i].first != prefer[i].second) where = prefer[i].second;
            }

            if(where == -1 || place[where] != -1) break;
            place[where] = i;
        }

        //well placed?
        bool flag = true;
        for(int p : place) {
            if(p == -1) {
                flag = false;
                break;
            }
        }
        if(!flag) continue;

        //check edges
        flag = true;
        for(int i = 0;i < M;i++) {
            int T = edges[i][2];
            int frogA = place[edges[i][0]];
            int frogB = place[edges[i][1]];
            if(interest[frogA][T] != interest[frogB][T]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "YES\n";
            for(int n : place) cout << n+1 << " ";
            exit(0);
        }
    }
    cout << "NO";

    return 0;
}