#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> types;
    
    for (int i = 0; i < clothes.size(); i++) {
        types[clothes[i][1]]++;
    }
    for (const auto& [key, value] : types) {
        answer *= (value + 1);
    }
    answer--;
    
    
    return answer;
}