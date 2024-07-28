#include <iostream>
#include <vector>
#include <unordered_map>
#define maxNode 20000
using namespace std;


//Node

int nodeParent[maxNode];
int nodeColor[maxNode];
int nodeMaxDepth[maxNode];
vector<int> nodeChilds[maxNode];

unordered_map<int,int> inputToMid;
int numNode = 0;

//helper
int input_to_id(int input) {
    if(input == -1) return -1;
    //input의 id를 내가 쓰는 m_id로 변환하기
    if(inputToMid.find(input) != inputToMid.end()) {
        return inputToMid[input];
    } else {
        inputToMid[input] = numNode++;
        return inputToMid[input];
    }
}

//노드 추가
bool addrecur(int m_id,int count) {
    //m_id에 count만큼이 허용되는지?
    if(m_id == -1) return true;
    if(nodeMaxDepth[m_id] < count) return false;
    return addrecur(nodeParent[m_id],count+1);
}
void addNode(int m_id,int p_id,int color,int max_depth) {
    if(p_id != -1) {
        //노드를 추가할 수 있는지 체크
        if(!addrecur(p_id,2)) return; //추가하지 않음
    }
    //추가할수 있다면
    nodeParent[m_id] = p_id;
    nodeColor[m_id] = color;
    nodeMaxDepth[m_id] = max_depth; 
    if(p_id != -1) nodeChilds[p_id].push_back(m_id);
}


//색깔 변경
void changeColor(int m_id,int color) {
    //m_id와 그 하위의 모든 노드의 color 변경
    nodeColor[m_id] = color;
    for(int child : nodeChilds[m_id]) {
        changeColor(child,color);
    }
}

//색깔 조회
int checkColor(int m_id) {
    return nodeColor[m_id];
}

//가치 조회
long long answer;
int caculateNode(int m_id) {
    //cout << "Calculating worth of " << m_id << "\n";
    //m_id의 하위 노드들의 가치를 계산하고, 현재 노드의 가치 더하기. color사용여부 bit를 리턴
    int bit = 1<<nodeColor[m_id];
    for(int child : nodeChilds[m_id]) {
        bit |= caculateNode(child);
    }
    int b = bit;
    int num_used = 0;
    while(b > 0) {
        num_used += b&1;
        b >>= 1;
    }
    answer += num_used * num_used;
    return bit;
}
long long query() {
    answer = 0;
    for(int i = 0;i < maxNode;i++) {
        if(nodeMaxDepth[i] == 0) continue;
        if(nodeParent[i] != -1) continue;
        //tree의 root인 i와 그 하위 노드들의 가치제곱합 누적하기
        caculateNode(i);
    }
    return answer;
}



int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int Q; cin >> Q;
    for(int q = 0;q < Q;q++) {
        int input; cin >> input;
        if(input == 100) {
            int a,b,c,d; cin >> a >> b >> c >> d;
            addNode(input_to_id(a),input_to_id(b),c,d);
        } else if(input == 200) {
            int a,b; cin >> a >> b;
            changeColor(input_to_id(a),b);
        } else if(input == 300) {
            int a; cin >> a;
            cout << checkColor(input_to_id(a)) << "\n";
        } else {
            cout << query() << "\n";
        }
    }
    return 0;
}