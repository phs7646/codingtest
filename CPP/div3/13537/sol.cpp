#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int arr[100001];
vector<vector<int>> _tree;

void _merge(vector<int>& left_child, vector<int>& right_child, vector<int>& merged) {
    int i = 0, j = 0;
    int left_size = left_child.size();
    int right_size = right_child.size();
    
    while (i < left_size && j < right_size) {
        if (left_child[i] <= right_child[j]) {
            merged.push_back(left_child[i]);
            i++;
        } else {
            merged.push_back(right_child[j]);
            j++;
        }
    }
    // 남은 요소들을 모두 추가
    while (i < left_size) {
        merged.push_back(left_child[i]);
        i++;
    }
    while (j < right_size) {
        merged.push_back(right_child[j]);
        j++;
    }
}

void build(int node,int left,int right) {
    if(left == right) {
        _tree[node] = vector<int>(1,arr[left]);
    } else {
        int mid = (left+right)/2;
        build(2*node,left,mid);
        build(2*node+1,mid+1,right);
        //merge
        _merge(_tree[2 * node], _tree[2 * node + 1], _tree[node]);
    }
}
int query(int node,int left,int right,int L,int R,int K) {
    //L부터 R사이에 K보다 큰 수의 갯수
    if(right < L || R < left) return 0; //not included
    if(L <= left && right <= R) {
        //fully included
        //현재 벡터에서 k보다 큰 수의 갯수 리턴
        auto it = upper_bound(_tree[node].begin(),_tree[node].end(),K);
        return _tree[node].end() - it;
    }
    int mid = (left+right)/2;
    int lsum = query(2*node,left,mid,L,R,K);
    int rsum = query(2*node+1,mid+1,right,L,R,K);
    return lsum+rsum;
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i = 1;i <= N;i++) cin >> arr[i];
    _tree.resize(N<<2);
    //build merge sort tree
    build(1,1,N);
    //query
    int M;cin >> M;
    for(int m = 0;m < M;m++) {
        int i,j,k; cin >> i >> j >> k;
        //i부터 j까지 k보다 큰 원소의 갯수
        cout << query(1,1,N,i,j,k) << "\n";
    }
    return 0;
}