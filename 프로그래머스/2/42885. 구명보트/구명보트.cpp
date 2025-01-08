#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> row;
    sort(people.begin(), people.end());
    
    for(const auto& person : people)
        row.push_back(person);
    int n = people.size();
    int rescue = 0;
    while(rescue < n) {
        if (row.front() + row.back() <= limit) {
            row.pop_front();
            row.pop_back();
            rescue += 2;
        }
        else if (row.front() + row.back() > limit) {
            row.pop_back();
            rescue += 1;
        }
        answer++;
    }
    return answer;
}