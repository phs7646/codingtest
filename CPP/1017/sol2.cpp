#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
vector<bool> isPrime(2001, true);

vector<vector<int>> adj;

bool trymatch(int tar, vector<int>& v,vector<bool>& visited,vector<int>& matching) {
    if(visited[tar]) return false;
    visited[tar] = true;
    for(int k : adj[tar]) {
        if(matching[k] == -1) {
            matching[k] = tar;
            return true;
        }
        if(trymatch(matching[k],v,visited,matching)) {
            matching[k] = tar;
            return true;
        }
    }
    return false;
}

int main() {
    
    //isprime[i] : 해당 수가 소수인지 아닌지
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= 45; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 2000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    //입력
    int N;
    int num_odd = 0;
    cin >> N;
    vector<int> v = vectorinput<int>(N);
    for(int n : v) if(n%2==1) num_odd++;
    if(num_odd != N/2) {
        cout << -1;
        return 0;
    }
    if(N == 2) {
        if(isPrime[v[0] + v[1]]) cout << v[1];
        else cout << -1;
        return 0;
    }
    adj = vector<vector<int>>(N);
    for(int i = 0;i < N-1;i++) {
        for(int j = i+1;j < N;j++) {
            if(isPrime[v[i]+v[j]]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    
    //해결
    int v0_remain = v[0]%2;
    vector<int> answer;
    for(int first : adj[0]) {
        //v[0] -> first 매칭
        vector<int> matching(N,-1);
        matching[first] = 0;
        bool success = true;
        for(int i = 1;i < N;i++) {
            if(v[i] % 2 != v0_remain) continue;
            vector<bool> visited(N,false);
            visited[0] = true;
            if(trymatch(i,v,visited,matching) == false) {
                success = false;
                break;
            }
        }
        if(success) answer.push_back(v[first]);
    }
    
    sort(answer.begin(),answer.end());
    if(answer.empty()) cout << -1;
    else vectorprint(answer);
    

    return 0;
}