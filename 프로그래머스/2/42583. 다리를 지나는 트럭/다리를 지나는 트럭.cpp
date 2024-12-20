#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q;
    for (int& i : truck_weights)
        q.push(i);
    
    queue<int> bridge;
    int nowWeight = 0;
    while(!q.empty()) {
        answer++;
        
        if(bridge.size() == bridge_length) {  //다리끝 맨앞트럭 나과는과정
            nowWeight -= bridge.front();
            bridge.pop();
        }
        
        if (weight >= nowWeight + q.front()) { //대기열에서 다리로
            if (q.size() == 1)
                answer += bridge_length; //마지막트럭이 다리 건너는걸 고려
            
            nowWeight += q.front();
            bridge.push(q.front());
            q.pop();
        }
        else {
            bridge.push(0);
        }
    }
    return answer;
}