#include <string>
#include <vector>

using namespace std;

int count = 0;

void dfs(string now, string word, string a, int& answer) {
    if (now == word) {
        answer = count;
        return;
    }
    
    if(now.size() >= 5)
        return;
    
    for (int i = 0; i < 5; i++) {
        count++;
        dfs(now + a[i], word, a, answer);
    }
}

int solution(string word) {
    int answer = 0;
    dfs("", word, "AEIOU", answer);
    return answer;
}