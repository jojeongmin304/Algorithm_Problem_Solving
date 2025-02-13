#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> stack;
    
    for (const auto& c : number) {
        while(stack.size() > 0 && c > stack.back()) {
            if (k > 0) {
                stack.pop_back();
                k--;
            }
            else break;
        }
        stack.push_back(c);
    }
    while (k > 0 && stack.size() > 0) {
        stack.pop_back();
        k--;
    }
    
    answer = string(stack.begin(), stack.end());
    if (answer[0] == '0') return "0";
    return answer;
}