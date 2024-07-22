#include<iostream>
#include<vector>
#include<string>
int mod = 1000003;
using namespace std;

vector<vector<int>> origin(50,vector<int>(50));
int N,S,E,T;
vector<vector<int>> matMul(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> ret(50, vector<int>(50, 0));
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            for (int k = 0; k < 50; ++k) {
                ret[i][j] += (A[i][k] * B[k][j])%mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}
vector<vector<int>> matPow(vector<vector<int>>& A,int P) {
    //A^P
    if(P == 0) {
        vector<vector<int>> ret(50,vector<int>(50));
        for(int i = 0;i < 50;i++) ret[i][i] = 1;
        return ret;
    }
    if(P == 1) {
        vector<vector<int>> ret = A;
        return ret;
    }
    vector<vector<int>> half = matPow(A,P/2);
    vector<vector<int>> halftohalf = matMul(half,half);
    if(P%2 == 0) return halftohalf;
    else return matMul(halftohalf,A);
}

int main() {
    cin >> N >> S >> E >> T;
    S--;E--;
    //build origin
    for(int i = 0;i < N;i++) {
        //i부터 i+4까지 한세트임
        //i가 본체라고 생각
        //i+4 -> i+3 -> i+2 -> i+1 -> i 연결됨
        for(int j = 0;j < 4;j++) {
            origin[5*i+j+1][5*i+j] = 1;
        }
    }
    for(int i = 0;i < N;i++) {
        string s; cin >> s;
        for(int j = 0;j < N;j++) {
            if(s[j] == '0') continue;
            int dist = s[j] - '0';
            //i부터 j까지 갈 때 dist가 필요함! 
            //i와 j+dist를 연결하면 진짜 j까지 가기위해 dist만큼 더 가야함!
            origin[5*i][5*j+dist-1] = 1;
        }
    }
    vector<vector<int>> result = matPow(origin,T);
    /*
    for(int i = 0;i < 5*N;i++) {
        for(int j = 0;j < 5*N;j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    */
    cout << result[5*S][5*E] % mod;
    return 0;
}