#include<iostream>
#include<vector>
#include<algorithm>
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
bool build(int pos, vector<int>& v) {
    int N = v.size();
    if(pos + 2 == N) return isPrime[v[pos] + v[pos+1]];
    for(int i = pos+1;i < N;i++) {
        if(isPrime[v[pos] + v[i]]) {
            swap(v[pos+1],v[i]);
            if(build(pos+2,v)) return true;
            swap(v[pos+1],v[i]);
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
    cin >> N;
    vector<int> v = vectorinput<int>(N);
    if(N == 2) {
        if(isPrime[v[0] + v[1]]) cout << v[1];
        else cout << -1;
        return 0;
    }
    vector<int> backup = v;
    vector<int> answer;
    for(int i = 1;i < N;i++) {
        if(isPrime[v[0] + v[i]]) {
            swap(v[1],v[i]);
            if(build(2,v)) answer.push_back(v[1]);
            v = backup;
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size() > 0) vectorprint(answer);
    else cout << -1;

    return 0;
}