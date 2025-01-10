#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> fruits;
    unordered_map<string, int> temp;
    
    for (int i = 0; i < want.size(); i++) {
        fruits[want[i]] = number[i];
    }
    int end = 9, start = end-9;
    while (end < discount.size()) {
        temp = fruits;
        for (int i = start; i <= end; i++) {
            if (temp[discount[i]] > 0)
                temp[discount[i]]--;
            else if (!temp[discount[i]])
                continue;
        }
        bool state = true;
        for (const auto& [key, value] : temp)
            if(value != 0) state = false;
        if(state) answer++;
        end++;
        start = end-9;
    }
    return answer;
}