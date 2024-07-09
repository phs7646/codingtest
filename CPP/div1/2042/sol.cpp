#include<iostream>
#include<vector>

using namespace std;
int N;
vector<long long> tree;
vector<long long> v;

long long build(int node,int start,int end) {
    if(start == end) {
        tree[node] = v[start];
        return tree[node];
    } else {
        int mid = (start + end)/2;
        tree[node] = build(2*node+1,start,mid) + build(2*node+2,mid+1,end);
        return tree[node];
    }
}

long long query(int node,int start,int end,int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return query(2*node+1,start,mid,left,right) + query(2*node+2,mid+1,end,left,right);
}

long long update(int node,int start,int end,int index, long long value) {
    if(index < start || end < index) return tree[node];
    if(start == end) {
        tree[node] = value;
        return tree[node];
    } 
    int mid = (start + end)/2;
    tree[node] = update(2*node+1,start,mid,index,value) + update(2*node+2,mid+1,end,index,value);
    return tree[node];
}

int main() {
    int M,K;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    v.resize(N);
    for(int i = 0;i < N;i++) cin>>v[i];
    tree.resize(4*N);
    build(0,0,N-1);
    for(int t = 0;t < M+K;t++) {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1) {
            update(0,0,N-1,b-1,c);
        } else {
            cout << query(0,0,N-1,b-1,c-1) << "\n";
        }
    }
    return 0;
}