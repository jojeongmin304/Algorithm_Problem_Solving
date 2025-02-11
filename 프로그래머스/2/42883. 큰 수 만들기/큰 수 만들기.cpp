#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> stack;
    for (char& c : number) {
        while (!stack.empty() && stack.back() < c) {
            if (k > 0) {
                stack.pop_back();
                k--;
            }
            else
                break;
        }
        stack.push_back(c);
    }
    while (k > 0) {
        stack.pop_back();
        k--;
    }
    
    return string(stack.begin(), stack.end());
}