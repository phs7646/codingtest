#include<iostream>

using namespace std;

#define MAX 1000001

int _data[MAX];
int tree[4*MAX];

//seg tree : 구간안의 사탕의 갯수
int update(int node,int left,int right,int key,int value) {
    //key를 value로 업데이트
    if(right < key || key < left) {
        return tree[node];
    }
    if(left == right) {
        tree[node] += value;
        _data[left] += value;
        return tree[node];
    }
    int mid = (left+right)/2;
    tree[node] = update(2*node,left,mid,key,value)+update(2*node+1,mid+1,right,key,value);
    return tree[node];
}

int query(int node,int left,int right,int start,int end) {
    //start부터 end까지 사탕의 총 갯수
    if(start <= left && right <= end) return tree[node];
    if(end < left || right < start) return 0;
    int mid = (left+right)/2;
    return query(2*node,left,mid,start,end)+query(2*node+1,mid+1,right,start,end);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    for(int n = 0;n < N;n++) {
        int A; cin >> A;
        if(A == 1) {
            int B; cin >> B;
            //B번째 맛잇는 사탕 pop하기
            //target 이분탐색 : query(0..target-1) < B && B <= query + _data[target] 
            int left = 0; int right = MAX-1;
            int target = -1;
            while(left <= right) {
                int mid = (left+right)/2;
                int accum = query(1,0,MAX-1,0,mid); //0..mid까지 총 사탕갯수
                if(accum < B) {
                    left = mid+1;
                    continue;
                }
                //accum >= B
                if(accum - _data[mid] < B) {
                    target = mid;
                    break;
                } else {
                    right = mid-1;
                }
            }
            cout << target << "\n";
            //사탕 1개 꺼내기
            update(1,0,MAX-1,target,-1);

        } else {
            int B,C; cin >> B >> C;
            //B 사탕 C개 추가
            update(1,0,MAX-1,B,C);
        }
    }
    return 0;
}