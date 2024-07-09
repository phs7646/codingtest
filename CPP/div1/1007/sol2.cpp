#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

pair<int,int> P[20];
int N;
int currentx;
int currenty;
int num;
double ans;
void search(int start, int choose) {

    if(choose == 0) {
        double dist = sqrt(pow(currentx,2) + pow(currenty,2));
        if(ans == -1 || dist < ans) ans = dist;
        return;
    }
    int prevx = currentx;
    int prevy = currenty;
    //unchoose start
    if(N-1-start > choose) search(start+1,choose);
    //choose start
    currentx += 2 * P[start].first;
    currenty += 2 * P[start].second;
    search(start+1,choose-1);
    currentx = prevx;
    currenty = prevy;

}

int main() {
    int T;
    cin >> T;
    
    for(int t = 0;t < T;t++) {
        cin >> N;
        currentx = 0;
        currenty = 0;
        num = 0;
        ans = -1;
        for(int i = 0;i < N;i++) {
            int t1,t2;
            cin >> t1 >> t2;
            P[i] = make_pair(t1,t2);
            //set default as minus
            currentx -= t1;
            currenty -= t2;
        }
        search(0,N/2);
        cout << fixed << setprecision(10) << ans << "\n";
        
    }


}