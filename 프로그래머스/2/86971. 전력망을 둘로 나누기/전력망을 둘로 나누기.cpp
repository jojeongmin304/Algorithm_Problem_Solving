#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int BFS(int a, int b, vector<vector<int>>& adj) {
    queue<int> q;
    vector<int> visited(101, 0);
    visited[a] = 1;
    q.push(a);
    int count = 1;
    
    while(!q.empty()) {
        int current = q.front(); q.pop();
        if (adj[current].size() == 0) continue;
        for (int& node : adj[current])
            if (visited[node] == 0 && node != b) {
                visited[node]++;
                q.push(node);
                count++;
            }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> adjList(n+1);
    
    for (const auto& wire : wires) {
        adjList[wire[0]].push_back(wire[1]);
        adjList[wire[1]].push_back(wire[0]);
    }
    
    for (const auto& wire : wires) {
        int left = BFS(wire[0], wire[1], adjList);
        int right = n - left;
        if (abs(left-right) < answer)
            answer = abs(left-right);
    }
    
    return answer;
}