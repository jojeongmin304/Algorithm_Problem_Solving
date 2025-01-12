#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    q.push({0, 0});
    maps[0][0] = 0;
    
    int distance = 1;
    
    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();

            if (x == n-1 && y == m-1) return distance;

            for (int i = 0; i < 4; i++) {
                if (x + dx[i] >= 0 && x + dx[i] < n
                    && y + dy[i] >= 0 && y + dy[i] < m
                    && maps[x+dx[i]][y+dy[i]] == 1) {
                    q.push({x+dx[i], y+dy[i]});
                    maps[x+dx[i]][y+dy[i]] = 0;
                }
            }
        }
        distance++;
    }
    
    return -1;
}