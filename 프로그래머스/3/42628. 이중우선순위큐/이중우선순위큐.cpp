#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    unordered_map<int, int> um;
    int size = 0;
    
    for (const auto& op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            maxq.push(num);
            minq.push(num);
            um[num]++;
            size++;
        }
        else if (op[0] == 'D' && size > 0) {
            if (op[2] == '1') {
                while (!maxq.empty() && um[maxq.top()] == 0)
                    maxq.pop();
                if (!maxq.empty()) {
                    um[maxq.top()]--;
                    maxq.pop();
                    size--;
                }
            }
            else {
                while (!minq.empty() && um[minq.top()] == 0)
                    minq.pop();
                if (!minq.empty()) {
                    um[minq.top()]--;
                    minq.pop();
                    size--;
                }
            }
        }
    }
    while (!maxq.empty() && um[maxq.top()] == 0)
        maxq.pop();
    while (!minq.empty() && um[minq.top()] == 0)
        minq.pop();
    
    if (size == 0) return {0, 0};
    return {maxq.top(), minq.top()};
}