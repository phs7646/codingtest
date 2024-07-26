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
            int roota = findRoot(a);
            int rootb = findRoot(b);
            int pr = 0;
            if(roota == 0 && rootb == 0) {
                //새로운 집합 추가
                root[a] = a;
                root[b] = a;
                nodeCount[a] = 2;
                pr = nodeCount[a];
            } else if(roota != 0 && rootb != 0) {
                //두 집합 합치기
                root[rootb] = roota;
                nodeCount[roota] += nodeCount[rootb];
                pr = nodeCount[roota];
            } else {
                //집합에 넣기
                if(roota == 0) {
                    root[a] = rootb;
                    nodeCount[rootb]++;
                    pr = nodeCount[rootb];
                } else {
                    root[b] = roota;
                    nodeCount[roota]++;
                    pr = nodeCount[roota];
                }
            }
            cout << pr << "\n";
        }
    }
    return 0;
}