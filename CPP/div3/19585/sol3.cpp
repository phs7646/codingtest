#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node
{
public:
    unordered_map<char, Node *> childs;
    bool isEnd = false;
};

class Trie
{
public:
    Node *head = new Node();
    void insert(string s)
    {
        Node *it = head;
        for (char c : s)
        {
            // it의 childs에 c를 추가하기
            if (it->childs.find(c) != it->childs.end())
            {
                it = it->childs[c];
            }
            else
            {
                it->childs[c] = new Node();
                it = it->childs[c];
            }
        }
        it->isEnd = true;
    }
    bool contains(string s,int startpos)
    {
        Node *it = head;
        for(;startpos < s.size();startpos++)
        {
            if (it->childs.find(s[startpos]) != it->childs.end())
            {
                it = it->childs[s[startpos]];
            }
            else
            {
                return false;
            }
        }
        return it->isEnd;
    }
    vector<int> findall(string s) {
        vector<int> ret;
        Node *it = head;
        for(int i = s.size()-1;i >= 0;i--) {
            if(it->isEnd) ret.push_back(i);
            if(it->childs.find(s[i]) == it->childs.end()) {
                break;
            } else {
                it = it->childs[s[i]];
            }
        }
        return ret;
    }
    bool solve(string s,const vector<string>& v) {
        Node *it = head;
        for(int i = 0;i < s.size();i++) {
            if(it->isEnd == true) {
                if(binary_search(v.begin(),v.end(),s.substr(i))) return true;
            }
            if(it->childs.find(s[i]) == it->childs.end()) {
                return false;
            } else {
                it = it->childs[s[i]];
            }
        }
        return false;
    }
};


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    Trie colorTrie;
    
    int C,N; cin >> C >> N;
    for(int i = 0;i < C;i++) {
        string s; cin >> s;
        colorTrie.insert(s);
    }
    vector<string> names(N);
    for(int i = 0;i < N;i++) {
        cin >> names[i];
    }
    sort(names.begin(),names.end());
    
    int Q; cin >> Q;
    for(int i = 0;i < Q;i++) {
        string s; cin >> s;
        if(colorTrie.solve(s,names)) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
    return 0;
}