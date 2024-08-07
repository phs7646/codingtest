#include <iostream>

using namespace std;

#define MAXNODE 100001
int N,M;
int root[MAXNODE];
int diff[MAXNODE];
int countN[MAXNODE];

pair<int,int> findRoot(int n) {
    //return root, diff
    if(root[n] == 0) {
        return {n,0};
    }
    pair<int,int> r = findRoot(root[n]);
    root[n] = r.first;
    diff[n] = r.second + diff[n];
    return {root[n],diff[n]};
}

void insert(int a,int b, int d) {
    pair<int,int> reta = findRoot(a);
    pair<int,int> retb = findRoot(b);
    if(reta.first == retb.first) {
        //notiong to do
        return;
    }
    
    //roota 밑에 rootb넣기
    int roota = reta.first;
    int rootb = retb.first;
    int diffa = reta.second; //roota 와 a는 diffa차이
    int diffb = retb.second; //rootb 와 b는 diffb차이
    if(countN[roota] > countN[rootb]) {
        countN[roota] += countN[rootb];
        root[rootb] = roota;
        diff[rootb] = diffa + d - diffb;
    } else {
        countN[rootb] += countN[roota];
        root[roota] = rootb;
        diff[roota] = diffb - d - diffa;
    }
    
    //roota 와 rootb의 차이는?
    //roota : (a - diffa)
    //rootb : (a + d - diffb)
    //roota -> rootb : diffa + d - diffb
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    do {
        //initialize
        //fill(root,root+MAXNODE,0); //0 is self
        //fill(diff,diff+MAXNODE,0);
        //fill(countN,countN+MAXNODE,1);
        for(int i = 1;i <= N;i++) {
            root[i] = 0;
            diff[i] = 0;
            countN[i] = 1;
        }
        for(int m = 0;m < M;m++) {
            char c; cin >> c;
            if(c == '!') {
                int a,b,d; cin >> a >> b >> d;
                insert(a,b,d);
            } else {
                int a,b; cin >> a >> b;
                pair<int,int> reta = findRoot(a);
                pair<int,int> retb = findRoot(b);
                if(reta.first != retb.first) {
                    cout << "UNKNOWN\n";
                } else {
                    cout << retb.second - reta.second << "\n";
                }
            }
        }
        //get next input
        cin >> N >> M;
    } while(!(N==0 && M==0));

    return 0;
}