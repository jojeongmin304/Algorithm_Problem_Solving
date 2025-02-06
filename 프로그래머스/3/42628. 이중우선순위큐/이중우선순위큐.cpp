#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    unordered_map<int, int> count;
    int size = 0;
    
    for (const auto& op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            maxq.push(num);
            minq.push(num);
            count[num]++;
            size++;
        }
        else if (op[0] == 'D' && size > 0) {
            if (op[2] == '1') {
                while(!maxq.empty() && count[maxq.top()] == 0)
                    maxq.pop();
                if (!maxq.empty()) {
                    count[maxq.top()]--;
                    maxq.pop();
                    size--;
                }
            }
            else {
                while(!minq.empty() && count[minq.top()] == 0)
                    minq.pop();  //이미 삭제된 값들은 정리
                if (!minq.empty()) {
                    count[minq.top()]--;
                    minq.pop();
                    size--;
                }
            }
        }
    }
    //마지막 정리
    while(!maxq.empty() && count[maxq.top()] == 0)
        maxq.pop();
    while(!minq.empty() && count[minq.top()] == 0)
        minq.pop();
    
    if (size == 0) return {0, 0};
    return {maxq.top(), minq.top()};
}