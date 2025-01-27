#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> um;
    
    for (char& c: s) {
        for (auto& [key, value] : um) {
            value++;
        }
        if(um[c]) {
            answer.push_back(um[c]);
            um[c] = 0;
        }
        else {
            um[c] = 0;
            answer.push_back(-1);
        }
    }
    return answer;
}