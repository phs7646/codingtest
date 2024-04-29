#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> on_bridge; // {w , time}
    int time = 1;
    int current = 0; //current weight on bridge
    int index = 0; //current truck
    
    while(index < truck_weights.size() || !on_bridge.empty()) {
        //unload
        if(!on_bridge.empty() && on_bridge.front().second + bridge_length <= time) {
            auto pair = on_bridge.front();
            on_bridge.pop();
            current -= pair.first;
            cout << "Unload " << pair.first << " on " << time << "\n";
        }
        
        //load
        if(index < truck_weights.size() && current + truck_weights[index] <= weight) {
            //can load new truck
            current += truck_weights[index];
            on_bridge.push({truck_weights[index],time});
            cout << "load " << truck_weights[index] << " on " << time << "\n";
            index++;
            time++;
        } else if(!on_bridge.empty()) {
            //skip time
            
            time = on_bridge.front().second + bridge_length;
            cout << "time skip to " << time << "\n";
        }
    }
    
    return time;
}