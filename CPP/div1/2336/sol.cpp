#include <iostream>
#include <vector>

using namespace std;

class ST {
    vector<int> tree1;
    vector<int> tree2;
    vector<pair<int,int>> data;
    int N;
    int build1(int node,int start,int end) {
        if(start == end) {
            tree1[node] = data[start].first;
        } else {
            int mid = (start+end)/2;
            tree1[node] = max(build1(node*2+1,start,mid),build1(node*2+2,mid+1,end));
        }
        return tree1[node];
    }
    int build2(int node,int start,int end) {
        if(start == end) {
            tree2[node] = data[start].second;
        } else {
            int mid = (start+end)/2;
            tree2[node] = max(build2(node*2+1,start,mid),build2(node*2+2,mid+1,end));
        }
        return tree2[node];
    }
    int query1(int node, int start, int end,int i, int j) {
        if(j < start || i > end) return 0;
        if(i <= start && end <= j) return tree1[node];
        int mid = (start+end)/2;
        return max(query1(node * 2 + 1, start, mid, i, j),query1(node * 2 + 2, mid + 1, end, i, j));
    }
    int query2(int node, int start, int end,int i, int j) {
        if(j < start || i > end) return 0;
        if(i <= start && end <= j) return tree2[node];
        int mid = (start+end)/2;
        return max(query2(node * 2 + 1, start, mid, i, j),query2(node * 2 + 2, mid + 1, end, i, j));
    }
public:
    int query1(int i,int j) {
        return query1(0,0,N-1,i,j);
    }
    int query2(int i,int j) {
        return query2(0,0,N-1,i,j);
    }
    ST(vector<pair<int,int>>& input) {
        data = input;
        N = input.size();
        tree1.resize(4 * N);
        tree2.resize(4 * N);
        build1(0,0,N-1);
        build2(0,0,N-1);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> v1(N);
    vector<int> v2(N);
    vector<pair<int,int>> score(N);
    for(int i = 0;i < N;i++) {
        cin >> v1[i];
    }
    for(int i = 0;i < N;i++) {
        cin >> v2[i];
    }
    for(int i = 0;i < N;i++) {
        int n;
        cin >> n;
        score[n-1] = {v1[i],v2[i]};
    }

    ST mytree(score);
    for(int i = 0;i < N;i++) {
        
    }

    

    return 0;
}