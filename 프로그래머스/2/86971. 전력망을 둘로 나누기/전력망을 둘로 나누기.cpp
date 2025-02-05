#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> adjList(n+1);
    for (const auto& wire: wires) {
        adjList[wire[0]].push_back(wire[1]);
        adjList[wire[1]].push_back(wire[0]);
    }
    
    for (auto& wire: wires) {
        queue<int> q;
        vector<int> visited(n+1, 0);
        int count = 1;
        visited[wire[0]] = 1;
        for (int& i : adjList[wire[0]])
            if (i != wire[1] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
                count++;
            }
        while(!q.empty()) {
            int current = q.front(); q.pop();
            
            for (auto& i : adjList[current]) {
                if (visited[i] != 1) {
                    visited[i] = 1;
                    q.push(i);
                    count++;
                }
            }
        }
        int rhs = count;
        int lhs = n - rhs;
        int gap = abs(rhs - lhs);
        if (gap < answer)
            answer = gap;
    }
    return answer;
}