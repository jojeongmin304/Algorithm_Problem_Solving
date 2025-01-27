#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> tic;
vector<string> a;

bool dfs(int cnt, string cur, vector<bool>& visited) {
    a.push_back(cur);
    
    if (cnt == tic.size())  //티켓의 개수와 같다면 리턴
        return 1;
    
    for (int i = 0; i < tic.size(); i++) {
        if (visited[i] == 1)
            continue;
        if (tic[i][0] != cur)  //출발지랑 현재위치랑 다르면 패스하는 관문
            continue;
        
        visited[i] = 1;
        bool T = dfs(cnt+1, tic[i][1], visited);
        if (T == 1)
            return 1;
        visited[i] = 0;
        a.pop_back();
    }
    return 0;
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), 0);
    tic = tickets;
    sort(tic.begin(), tic.end());
    dfs(0, "ICN", visited);
    
    return a;
}