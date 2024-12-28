#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0 ; i < s.size(); i++) {
        stack<char> stk;
        bool isValid = true;
        
        for (int j = 0; j < s.size(); j++) {
            char it = s[(i + j) % s.size()];
            
            if (it == '(' || it == '{' || it == '[')
                stk.push(it);
            else {
                if (stk.empty()) {
                    isValid = false;
                    break;
                }
                
                if (it == ')' && stk.top() == '(' ||
                    it == '}' && stk.top() == '{' ||
                    it == ']' && stk.top() == '[')
                    stk.pop();
                else {
                    isValid = false;
                    break;
                }
            }
        }
        
        if (isValid && stk.empty()) answer++;
    }
    
    return answer;
}