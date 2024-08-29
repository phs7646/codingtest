#include<iostream>
#define MAX 1000001
using namespace std;

typedef long long ll;

ll _tree[4*MAX];
ll _data[MAX];
ll _lazy[4*MAX];
int N,M,K;


void _init(int node,int left, int right) {
    if(left==right) {
        _tree[node] = _data[left];
        return;
    }
    int mid = (left+right)/2;
    _init(2*node,left,mid);
    _init(2*node+1,mid+1,right);
    _tree[node] = _tree[node*2] + _tree[node*2+1];
}
void _applyLazy(int node, int left, int right) {
    _tree[node] += (right - left + 1) * _lazy[node];
    if (left != right) {
        _lazy[2 * node] += _lazy[node];
        _lazy[2 * node + 1] += _lazy[node];
    }
    _lazy[node] = 0;
}
void _update(int node,int left,int right, int L, int R, ll value) {
    if(_lazy[node] != 0) _applyLazy(node,left,right);
    //out of range
    if(right < L || R < left) return;
    //include
    if(L <= left && right <= R) {
        _tree[node] += (right-left+1) * value;
        if(left != right) {
            _lazy[node*2] += value;
            _lazy[node*2+1] += value;
        }
        return;
    }
    int mid = (left+right)/2;
    _update(2*node,left,mid,L,R,value);
    _update(2*node+1,mid+1,right,L,R,value);
    _tree[node] = _tree[2*node] + _tree[2*node+1]; //현재 상태 반영
}
ll _query(int node,int left, int right, int L, int R) {
    if(_lazy[node] != 0) _applyLazy(node,left,right);
    //out of range
    if(right < L || R < left) return 0;
    //include
    if(L <= left && right <= R) return _tree[node];
    int mid = (left+right)/2;
    ll lsum = _query(2*node,left,mid,L,R);
    ll rsum = _query(2*node+1,mid+1,right,L,R);
    return lsum + rsum;
}


void updateRange(int L,int R,ll value) {
    _update(1,1,N,L,R,value);
}
ll queryRange(int L,int R) {
    return _query(1,1,N,L,R);
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    M += K;
    for(int i = 1;i <= N;i++) cin >> _data[i];
    _init(1,1,N);
    for(int m = 0;m < M;m++) {
        int a; cin >> a;
        if(a == 1) {
            int b,c; ll d; cin >> b >> c >> d;
            updateRange(b,c,d);
        } else {
            int b,c; cin >> b >> c;
            cout << queryRange(b,c) << "\n";
        }
    } 
    return 0;
}