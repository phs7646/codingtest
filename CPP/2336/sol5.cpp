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
            if (index <= mid) {
                update(node * 2 + 1, start, mid, index, val);  
            } else {
                update(node * 2 + 2, mid + 1, end, index, val);  
            }
            tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]); 
        }
        return tree[node];
    }

public :
    ST(int n) {
        N = n+1;
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

    vector<int> v1(N+1); // v1[i] : i번의 등수
    vector<int> v2(N+1);
    vector<pair<int,int>> score; 
    for(int i = 1;i <= N;i++) {
        int num;
        cin >> num;
        v1[num] = i;
    }
    for(int i = 1;i <= N;i++) {
        int num;
        cin >> num;
        v2[num] = i;
    }
    for(int i = 1;i <= N;i++) {
        int num;
        cin >> num;
        score.push_back({v1[num],v2[num]});

    }


    ST tree(N); //1번시험에서 i등을한애의 2번시험등수는 j
    tree.update(0,N+1);
    int count = 0;
    for(int i = 0;i < N;i++) {
        
        int a = score[i].first; // 1 ~ N
        int b = score[i].second; // 1 ~ N
        //cout << "Target is " << a << "," << b << "\n";
        //세번쨰 시험에서 i등을 한 애의 1번,2번 시험 등수는 a,b
        if(tree.query(0,a-1) > b) {
            //cout << "Count ++ \n";
            count++;
        }
        tree.update(a,b);

    }
    cout << count;
    return 0;
}