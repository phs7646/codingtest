#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> ans(10,0);

void L(int l,int time) {
    if(time == 0) return;
    int value = l;
    value *= static_cast<int>(pow(10,l-1));
    value *= time;
    for(int i = 0;i < 10;i++) {
        ans[i] += value;
    }
}

int vectonum(vector<int>v) {
    if(v.empty()) return 1;
    int ret = 0;
    for(int n : v) ret = ret*10 + n;
    return ret+1;
}
int main() {
    int N;
    
    cin >> N;
    vector<int> v;
    while(N > 0) {
        int n = N % 10;
        v.push_back(n);
        N /= 10;
    }
    reverse(v.begin(),v.end());
    
    //zeros will count too much when very first number is 0
    int zero_base = 0;
    for(int i = 0;i < v.size();i++) zero_base = zero_base * 10 + 1;
    ans[0] = -1 * zero_base;

    while(!v.empty()) {
        int index = v.size();
        int l = index-1;
        //k is front number, l is index of k
        int k = v.front();
        v.erase(v.begin());
        
        //for lower nums, += l * 10^(l-1) for k times
        L(l,k);

        //for front nums, += 10^l 
        int ntime = static_cast<int>(pow(10,l));
        for(int n = 0;n < k;n++) {
            ans[n] += ntime; 
        }

        //for k, += lower num
        ans[k] += vectonum(v);

        //cout << "top number was " << k << "\n";
        //for(int n : ans) cout << n << " ";
        //cout << "\n";
    }
    for(int n : ans) cout << n << " ";

    return 0;
}