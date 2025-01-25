#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& tree, int sp, int cp) {
    int cnt = 1;
    queue<int> q;
    vector<int> visited(101);
    visited[sp] = 1;
    
    for (int branch : tree[sp])
        if(!visited[branch] && branch != cp) {
            visited[branch] = 1;
            q.push(branch);
            cnt++;
        }
    while (!q.empty()) {
        int now = q.front(); q.pop();
        
        for (int branch : tree[now])
            if (!visited[branch]) {
                visited[branch] = 1;
                q.push(branch);
                cnt++;
            }
    }
    return cnt;
}







int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    vector<vector<int>> tree(101);
    //그래프관계 인접리스트 만들기
    for (vector<int> wire : wires) {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    for (vector<int> wire : wires) {
        int rhs = BFS(tree, wire[0], wire[1]);
        int lhs = n - rhs;
        
        if(abs(rhs-lhs) < answer)
            answer = abs(rhs-lhs);
    }
    
    return answer;
}