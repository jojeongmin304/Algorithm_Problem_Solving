#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue<string> C1;
    queue<string> C2;
    
    for (const auto& word : cards1)
        C1.push(word);
    for (const auto& word : cards2)
        C2.push(word);
    for (const auto& word : goal) {
        if (word == C1.front())
            C1.pop();
        else if (word == C2.front())
            C2.pop();
        else
            return "No";
    }
    
    return answer;
}