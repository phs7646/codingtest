#include <iostream>
#include <vector>

using namespace std;

class ST {
    vector<int> tree;
    int N;
    int query(int node,int start,int end,int i, int j) {
        if(j < start || i > end) return N+1;
        if(i <= start && end <= j) return tree[node];
        int mid = (start+end)/2;
        return min(query(node * 2 + 1, start, mid, i, j),query(node * 2 + 2, mid + 1, end, i, j));
    }
    int update(int node,int start,int end,int index,int val) {
        if(start == end) {
            tree[node] = val;
        } else {
            int mid = (start+end)/2;
            if(start <= index && index <= mid) {
                tree[node] = min(update(node * 2 + 1,start,mid,index,val),tree[node*2+2]);
            } else {
                tree[node] = min(tree[node*2+1],update(node * 2 + 2,start,mid,index,val));
            }
        }
        return tree[node];
    }

public :
    ST(int n) {
        N = n;
        tree.resize(N * 4,N+1);
    }
    int query(int i,int j) {
        int ret =  query(0,0,N-1,i,j);
        //cout <<"querying " << i << " to " << j << " is " << ret << "\n";
        return ret;
    }
    void update(int index,int val) {
        //cout << "updating " << index << " to " << val << "\n";
        update(0,0,N-1,index,val);
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> v1(N); // v1[i] : i번의 등수
    vector<int> v2(N); 
    vector<pair<int,int>> score(N); 
    for(int i = 0;i < N;i++) {
        int t;
        cin >> t;
        v1[t-1] = i;
    }
    for(int i = 0;i < N;i++) {
        int t;
        cin >> t;
        v2[t-1] = i;
    }
    for(int i = 0;i < N;i++) {
        int t;
        cin >> t;
        score[i] = {v1[t-1],v2[t-1]};
    }



    ST tree(N); //1번시험에서 i등을한애의 2번시험등수는 j
    int count = 0;
    for(int i = 0;i < N;i++) {
        int a = score[i].first;
        int b = score[i].second;
        //cout << "target is " << a << " , " << b << "\n";
        //세번쨰 시험에서 i등을 한 애의 1번,2번 시험 등수는 a,b
        if(tree.query(0,a) > b) count++;
        tree.update(a,b);

    }
    cout << count;
    return 0;
}