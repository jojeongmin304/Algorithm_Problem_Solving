#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    vector<char> stack;
    for (char num : number) {
        while (!stack.empty() && stack.back() < num) {
            if (k > 0) {
                stack.pop_back();
                --k;
            }
            else break;
        }
        stack.push_back(num);
    }
    if (k > 0) {
        for (int i = 0; i < k; i++) {
            stack.pop_back();
        }
    }
    return string(stack.begin(), stack.end());
}