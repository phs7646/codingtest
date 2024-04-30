#include<iostream>
#include<vector>

using namespace std;

/* helper functions */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}

template<typename T>
vector<T> vectorinput(int n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

/* codes */

int recur(int player, const vector<vector<int>>& v, vector<bool>& occup) {
    if(player >= 11) {
        for(bool b : occup) if(!b) return -1;
        return 0;
    }
    //choose player i's position
    int maximum = -1;
    for(int i = 0;i < 11;i++) {
        if(occup[i] == false && v[player][i] != 0) {
            occup[i] = true;
            int value = recur(player+1, v, occup);
            if(value != -1) maximum = max(maximum,value + v[player][i]);
            occup[i] = false;
        }
    }
    return maximum;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        //input
        int N = 11;
        vector<vector<int>> v(N,vector<int>(N));
        for(int i = 0;i < N;i++) v[i] = vectorinput<int>(N);
        //solve
        vector<bool> occup(N,false);
        cout << recur(0,v,occup) << endl;
    }
    return 0;
}