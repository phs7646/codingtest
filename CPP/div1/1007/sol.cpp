#include <iostream>
#include <math.h>

using namespace std;

pair<int,int> P[20];
int used[20];
int num;
int N;
double ans;
int xval;
int yval;
void search() {
    if(num == N) {
        //cout << xval << " " << yval << "\n";
        double value = sqrt(pow(xval,2) + pow(yval,2));
        if(ans == -1 || value < ans) ans = value;
        return;
    }
    int min = 2147483647;
    //pick first
    int first = 0;
    while(used[first]) first++;

    //match first and second
    used[first] = 1;
    num+=2;
    for(int second = first+1; second < N; second++) {
        if(used[second] == 1) continue;
        used[second] = 1;
        // fisrt -> second
        xval += P[second].first - P[first].first;
        yval += P[second].second - P[first].second;
        search();
        xval -= P[second].first - P[first].first;
        yval -= P[second].second - P[first].second;
        // second -> first
        xval -= P[second].first - P[first].first;
        yval -= P[second].second - P[first].second;
        search();
        xval += P[second].first - P[first].first;
        yval += P[second].second - P[first].second;
        used[second] = 0;
    }
    num-=2;
    used[first] = 0;

}

int main() {
    int T;
    cin >> T;
    
    for(int t = 0;t < T;t++) {
        xval = 0;
        yval = 0;
        ans = -1;
        num = 0;
        cin >> N;
        for(int i = 0;i < N;i++) {
            int t1,t2;
            cin >> t1 >> t2;
            P[i] = make_pair(t1,t2);
            used[i] = 0;
        }
        search();
        cout << ans;
    }


}