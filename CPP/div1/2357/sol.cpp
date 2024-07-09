#include<iostream>
#include<vector>
#include<climits>

using namespace std;
vector<int> v;
vector<int> mintree;
vector<int> maxtree;

int buildmax(int node,int start,int end) {
    if(start == end) return maxtree[node] = v[start];
    int mid = (start+end)/2;
    return maxtree[node] = max(buildmax(2*node+1,start,mid),buildmax(2*node+2,mid+1,end));
}

int buildmin(int node,int start,int end) {
    if(start == end) return mintree[node] = v[start];
    int mid = (start+end)/2;
    return mintree[node] = min(buildmin(2*node+1,start,mid),buildmin(2*node+2,mid+1,end));
}

int querymax(int node,int start,int end,int left, int right) {
    if(end < left || right < start) return INT_MIN;
    if(left <= start && end <= right) return maxtree[node];
    int mid = (start+end)/2;
    return max(querymax(2*node+1,start,mid,left,right),querymax(2*node+2,mid+1,end,left,right));
}

int querymin(int node,int start,int end,int left, int right) {
    if(end < left || right < start) return INT_MAX;
    if(left <= start && end <= right) return mintree[node];
    int mid = (start+end)/2;
    return min(querymin(2*node+1,start,mid,left,right),querymin(2*node+2,mid+1,end,left,right));
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    v.resize(N);
    for(int i = 0;i < N;i++) cin>>v[i];
    mintree.resize(4*N,INT_MAX);
    maxtree.resize(4*N,INT_MIN);
    

    buildmax(0,0,N-1);
    buildmin(0,0,N-1);

    for(int i = 0;i < M;i++) {
        int a,b;
        cin >> a >> b;
        cout << querymin(0,0,N-1,a-1,b-1) << " " << querymax(0,0,N-1,a-1,b-1) << "\n";
    }

    return 0;
}