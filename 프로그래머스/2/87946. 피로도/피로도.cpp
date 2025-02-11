#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int current, vector<int>& check, int& fatigue, int count, vector<vector<int>> dungeons) {
    //재귀종료조건
    if (fatigue < dungeons[current][0])
        return;
    
    if (count > answer) answer = count;
    check[current]++;
    fatigue -= dungeons[current][1];
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (current == i) continue;
        
        if (check[i] == 0)
            DFS(i, check, fatigue, count+1, dungeons);
    }
    check[current] = 0;
    fatigue += dungeons[current][1];
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> check(dungeons.size(), 0);
    int fatigue = k;
    for (int i = 0; i < dungeons.size(); i++) {
        DFS(i, check, fatigue, 1, dungeons);
    }
    
    return answer;
}