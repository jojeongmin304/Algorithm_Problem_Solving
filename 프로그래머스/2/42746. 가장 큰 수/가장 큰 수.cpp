#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int& num1, int& num2) {
    string a = to_string(num1);
    string b = to_string(num2);
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), check);
    
    for (int& num : numbers)
        answer += to_string(num);
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}