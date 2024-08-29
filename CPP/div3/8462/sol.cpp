#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
ll blockSIZE = sqrt(100000);
typedef class Query {
public :
    ll left;
    ll right;
    ll index;
    Query(ll a,ll b,ll i) : left(a),right(b),index(i) {}
    bool operator < (const Query& o) const {
        ll f = left/blockSIZE;
        ll s = o.left/blockSIZE;
        if(f != s) return f<s;
        else return right<o.right;
    }
} Query;
unordered_map<ll,ll> hm;


int main() {
    ll N,T; cin >> N >> T;
    vector<ll> A(N);
    for(ll i = 0;i < N;i++) cin >> A[i];
    vector<Query> queries;
    vector<ll> ret(T);
    for(ll i = 0;i < T;i++) {
        ll a,b; cin >> a >> b;
        queries.emplace_back(a-1,b-1,i);
    }
    

    sort(queries.begin(),queries.end());
    //build first quer
    ll left = queries[0].left;
    ll right = queries[0].right;
    for(ll i = left; i <= right;i++) hm[A[i]]++;
    ll cur = 0;
    for(pp p : hm) {
        cur += p.first * p.second * p.second;
    }
    ret[queries[0].index] = cur;
    
    //build remaining query
    for(ll i = 1;i < T;i++) {
        ll _left = queries[i].left;
        ll _right = queries[i].right;
        ll index = queries[i].index;
        //move poller
        while(right < _right) {
            right++;
            //A[right] 를 추가해야함
            ll n = hm[A[right]]; //n^2 * A[right] - > (n+1)^2 * A[right] 해야 하니까 (2n+1) * A[right]) 더해주면됨
            cur += (2*n+1)*A[right];
            hm[A[right]]++;
        }
        while(right > _right) {
            //A[right]를 빼줘야함
            ll n = hm[A[right]]; 
            cur -= (2*n-1)*A[right];
            hm[A[right]]--;
            right--;
        }
        while(left < _left) {
            //A[left]를 빼줘야함
            ll n = hm[A[left]]; //n^2 * A[left] -> (n-1)^2 * A[left]  해야 하니까  (2n-1) * A[left] 해주면됨
            cur -= (2*n-1)*A[left];
            hm[A[left]]--;
            left++;
        }
        while(left > _left) {
            left--;
            //A[left]를 추가해야함
            ll n = hm[A[left]]; //n^2 * A[left] - > (n+1)^2 * A[left] 해야 하니까 (2n+1) * A[left]) 더해주면됨
            cur += (2*n+1)*A[left];
            hm[A[left]]++;
        }
        ret[index] = cur;
    }

    for(ll ans : ret) cout << ans << "\n";
    return 0;
}