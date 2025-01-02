#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = bridge_length;
    queue<int> bridge;
    int nowWeight = 0;
    
    for (int i = 0; i < truck_weights.size(); i++) {
        if (!bridge.empty() && bridge.size() == bridge_length) {
            nowWeight -= bridge.front();
            bridge.pop();
        }
        
        
        if (nowWeight + truck_weights[i] <= weight) {
            bridge.push(truck_weights[i]);
            nowWeight += truck_weights[i];
        }
        else {
            bridge.push(0);
            i--;
        }
        answer++;
    }
    return answer;
}