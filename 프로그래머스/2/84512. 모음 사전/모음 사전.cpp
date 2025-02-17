#include <string>
#include <vector>

using namespace std;

int count = 0;

void dfs(string current, string goal, int& answer) {
    string aeiou = "AEIOU";
    if (current == goal) {
        answer = count;
        return;
    }
    if (current.size() >= 5)
        return;
    
    for (char c : aeiou) {
        count++;
        dfs(current + c, goal, answer);
    }
    
    return;
}

int solution(string word) {
    int answer = 0;
    dfs("", word, answer);
    return answer;
}