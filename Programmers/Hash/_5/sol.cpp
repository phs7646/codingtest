#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    //장르 : 플레이수, 1위, 2위 int,int,int
    unordered_map<string,vector<int>> map;
    for(int i = 0;i < genres.size();i++) {
        vector<int>& v = map[genres[i]];
        if(v.empty()) {
            v.push_back(plays[i]);
            v.push_back(i);
            v.push_back(-1);
        } else {
            v[0] += plays[i];
            if(plays[i] > plays[v[1]]) {
                v[2] = v[1];
                v[1] = i;
            } else if(v[2] == -1 || plays[i] > plays[v[2]]) {
                v[2] = i;
            }
        }
    }
    /*
    for(auto pair : map) {
        cout << pair.first << " ";
        for(int v : pair.second) {
            cout << v << " ";
        }
        cout << "\n";
    } */
    vector<pair<int,string>> forsort;
    for(auto pair : map) {
        forsort.push_back({pair.second[0],pair.first});
    }
    sort(forsort.begin(),forsort.end());
    reverse(forsort.begin(),forsort.end());
    
    vector<int> answer;
    for(auto pair : forsort) {
        int first = map[pair.second][1];
        int second = map[pair.second][2];
        answer.push_back(first);
        if(second != -1) answer.push_back(second);
    }
    return answer;
    
}