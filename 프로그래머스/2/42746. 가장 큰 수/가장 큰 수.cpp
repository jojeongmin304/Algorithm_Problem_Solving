#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    string str_a = to_string(a);
    string str_b = to_string(b);
    return str_a + str_b > str_b + str_a;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    
    for (int& i : numbers)
        answer += to_string(i);
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}