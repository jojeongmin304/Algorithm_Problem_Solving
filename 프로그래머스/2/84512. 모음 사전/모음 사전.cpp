#include <string>
#include <vector>

using namespace std;

int count = 0;

void DFS(string current, string goal, string AEIOU,int& answer) {
    if (current == goal) {
        answer = count;
        return;
    }
    if (current.size() >= 5)
        return;
    
    for (int i = 0; i < 5; i++) {
        count++;
        DFS(current+AEIOU[i], goal, AEIOU, answer);
    }
}

int solution(string word) {
    int answer = 0;
    DFS("", word, "AEIOU", answer);
    
    return answer;
}