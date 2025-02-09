#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int max = 0;
    
    sort(dungeons.begin(), dungeons.end(), cmp);
    
    while(next_permutation(dungeons.begin(), dungeons.end())) {
        int fatigue = k;
        int count = 0;
        for (const auto& dungeon : dungeons) {
            if(fatigue >= dungeon[0]) {
                fatigue -= dungeon[1];
                count++;
            }
            else break;
        }
        if (count > answer) answer = count;
    }
    return answer;
}