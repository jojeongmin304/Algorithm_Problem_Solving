#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int pre = -1;
    for (const auto& i : arr) {
        if (i == pre) continue;
        else answer.push_back(i);
        pre = i;
    }
    return answer;
}