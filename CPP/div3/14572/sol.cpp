#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
int N,K,D;
ll countValue(vector<int>& counter,int num) {
    //등장한 알고리즘 수 - 모두가 아는 알고리즘 
    int all = 0;
    int know = 0;
    for(int j = 0;j < K;j++) {
        if(counter[j] > 0) all++;
        if(counter[j] == num) know++;
    }
    return (ll)(all-know) * num;
}

//그리디! : 학생수는 최대한 많이
int main() {
    cin >> N >> K >> D;
    vector<pp> students;
    for(int i = 0;i < N;i++) {
        int M,d; cin >> M >> d;
        int know = 0;
        for(int j = 0;j < M;j++) {
            int a; cin >> a;
            know |= (1<<(a-1));
        }
        students.emplace_back(d,know);
    }
    sort(students.begin(),students.end());
    int left = 0;
    int right = -1;
    vector<int> counter(K);
    //build first query
    while(right+1 < N && students[right+1].first <= students[left].first+D) {
        right++;
        //count right
        for(int j = 0;j < K;j++) {
            if(students[right].second & (1<<j)) counter[j]++;
        }
    }
    ll answer = countValue(counter,right-left+1);
    
    while(right < N) { //if right become N, means end
        int oldD = students[left].first;
        //delete left
        while(left < N && students[left].first == oldD) {
            for(int j = 0;j < K;j++) {
                if(students[left].second & (1<<j)) counter[j]--;
            }
            left++;
        } 
        if(left == N) break;//no more students...
        
        //append right
        while(right+1 < N && students[right+1].first <= students[left].first+D) {
            //add right+1
            right++;
            for(int j = 0;j < K;j++) {
                if(students[right].second & (1<<j)) counter[j]++;
            }
        }
        answer = max(answer,countValue(counter,right-left+1));
    }
    cout << answer;
    return 0;
}