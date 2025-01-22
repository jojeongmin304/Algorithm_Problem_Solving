#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> check(50, 0);
int answer = 50;

void dfs(string nowword, string target, vector<string> words, int count) {
    if (nowword == target) {
        if (count < answer)
            answer = count;
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (check[i] == 1) continue;
        
        int gap = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (gap > 1) break;
            
            if (words[i][j] != nowword[j])
                gap++;
        }
        if (gap == 1) {
            check[i] = 1;
            dfs(words[i], target, words, count+1);
            check[i] = 0; //상태 복구
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;  //target단어 자체가 words에 없는 경우
    dfs(begin, target, words, 0);
    return answer;
}