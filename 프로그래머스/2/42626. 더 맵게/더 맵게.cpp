#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int food = 0;
    priority_queue pq(scoville.begin(), scoville.end(), greater<int>());
    
    while (pq.top() < K) {
        if (pq.size() <= 1)
            return -1;
        
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        food = first + (2*second);
        
        pq.push(food);
        answer++;
    }
    
    return answer;
}