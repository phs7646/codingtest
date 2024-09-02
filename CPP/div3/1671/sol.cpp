#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int N;

typedef class shark{
public:
    int a,b,c;
    shark(int x,int y,int z) : a(x),b(y),c(z) {}
    bool operator < (const shark& s2) {
        return a > s2.a;
    }
} shark;

vector<int> canEat[51];
int ateBy[51];
vector<bool> visited;

bool tryMatch(int x) {
    for(int nxt : canEat[x]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        if(ateBy[nxt] == 0 || tryMatch(ateBy[nxt])) {
            ateBy[nxt] = x;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    vector<shark> val; val.emplace_back(0,0,0);
    for(int i = 0;i < N;i++) {
        int a,b,c; cin >> a >> b >> c;
        val.emplace_back(a,b,c);
    }
    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= N;j++) {
            //can shark i can eat j?
            shark& s1 = val[i];
            shark& s2 = val[j];
            //일방적으로 s1이 s2를 먹거나, 정확히 동일한 수치인데 i<j이거나
            bool isSame = s1.a == s2.a && s1.b == s2.b && s1.c == s2.c;
            bool eat = s1.a >= s2.a && s1.b >= s2.b && s1.c >= s2.c;
            if((!isSame && eat) || (isSame && i<j)) canEat[i].emplace_back(j);
        }
    }

    //먹는다!를 이분매칭 (두번씩)
    int count = 0;

    for(int i = 1;i <= N;i++) {
        visited = vector<bool>(N+1);
        if(tryMatch(i)) count++;
        visited = vector<bool>(N+1);
        if(tryMatch(i)) count++;
    }

    cout << N-count;
    return 0;
}