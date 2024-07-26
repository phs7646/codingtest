#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int root[200007];
int nodeCount[200007];

unordered_map<string,int> dic;
int userCount = 0;

int nameToNum(string s) {
    if(dic.find(s) != dic.end()) return dic[s];
    dic[s] = ++userCount;
    return userCount;
}

int findRoot(int i) {
    if(i == root[i]) return i;
    if(root[i] == 0) return 0;
    return root[i] = findRoot(root[i]);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 0;t < T;t++) {
        int F; cin >> F;
        //initialize
        fill(root,root+200007,0);
        fill(nodeCount,nodeCount+200007,0);
        userCount = 0;
        dic.clear();
        //logic
        for(int f = 0;f < F;f++) {
            string s1,s2; cin >> s1 >> s2;
            int a = nameToNum(s1);
            int b = nameToNum(s2);
            if(root[a] == 0) {
                root[a] = a;
                nodeCount[a] = 1;
            }
            if(root[b] == 0) {
                root[b] = b;
                nodeCount[b] = 1;
            }

            int roota = findRoot(a);
            int rootb = findRoot(b);
            if(roota != rootb) {
                root[rootb] = roota;
                nodeCount[roota] += nodeCount[rootb];
                nodeCount[rootb] = 0; // 합쳐진 노드의 카운트를 0으로 초기화
            }
            cout << nodeCount[roota] << "\n";
        }
    }
    return 0;
}