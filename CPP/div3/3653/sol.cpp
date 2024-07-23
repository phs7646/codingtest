#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;
int _data[200000];
int _tree[800000];
int height[100000];

int buildTree(int node,int start,int end) {
    if(start == end) return _tree[node] = _data[start];
    if(start > end) return 0;
    int mid = (start+end)/2;
    return _tree[node] = buildTree(2*node+1,start,mid) + buildTree(2*node+2,mid+1,end);
}
int updateTree(int node,int start,int end,int index) {
    if(index < start || end < index) return _tree[node];
    else if(start == end) {
        if(start == index) return _tree[node] = _data[index];
        else return _tree[node];
    }
    int mid = (start+end)/2;
    return _tree[node] = updateTree(2*node+1,start,mid,index) + updateTree(2*node+2,mid+1,end,index);
}
int searchTree(int node,int start,int end,int left,int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return _tree[node];
    int mid = (start+end)/2;
    return searchTree(2 * node + 1, start, mid, left, right)+searchTree(2 * node + 2, mid + 1, end, left, right);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 0;t < T;t++) {
        cin >> N >> M;
        int len = N+M;
        int len2 = 4*len;
        for(int i = 0;i < N;i++) {
            height[i] = N-i-1;
        }
        for(int i = 0;i < N;i++) {
            _data[i] = 1;
        }
        for(int i = N;i < len;i++) {
            _data[i] = 0;
        }
        for(int i = 0;i < len2;i++) {
            _tree[i] = 0;
        }
        buildTree(0,0,len-1);
        for(int j = 0;j < M;j++) {
            int target; cin >> target; target--;
            //현재 target의 height보다 높은 곳에 있는 cd의 갯수
            cout << searchTree(0,0,len-1,height[target]+1,len-1) << " ";
            _data[height[target]] = 0; // 현재 위치 0으로
            updateTree(0,0,len-1,height[target]); //업데이트
            height[target] = N + j; // 맨위로
            _data[height[target]] = 1; //현재 위치 1로
            updateTree(0,0,len-1,height[target]); //업데이트
        }
        cout << "\n";
    }

    return 0;
}