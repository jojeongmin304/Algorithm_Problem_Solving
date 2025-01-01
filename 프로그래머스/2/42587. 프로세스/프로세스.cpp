#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue pq(priorities.begin(), priorities.end());
    
    while(true) {
        if (pq.top() == priorities[0]) {
            if (location == 0)
                return answer;
            else {
                pq.pop();
                priorities.erase(priorities.begin());
                answer++;
            }
        }
        else if (pq.top() != priorities[0]) {
            if (location == 0)
                location = priorities.size();
            
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
        }
        location--;
    }
    return answer;
}