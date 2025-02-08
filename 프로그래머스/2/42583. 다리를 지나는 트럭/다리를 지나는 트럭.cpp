#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int nowWeight = 0;
    queue<int> bridge;
    queue<int> wait;
    
    while(bridge.size() < bridge_length)
        bridge.push(0);
    
    for (int& i : truck_weights) {
        wait.push(i);
    }
    
    while(!bridge.empty()) {
        nowWeight -= bridge.front(); bridge.pop();
        
        if (!wait.empty()) {
            if (nowWeight+wait.front() <= weight) {
                bridge.push(wait.front()); 
                nowWeight += wait.front();
                wait.pop();
            }
            else
                bridge.push(0);
        }
        time++;
    }
    
    return time;
}