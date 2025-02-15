#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int current, int index, vector<int>& numbers, int target) {
    if (index == numbers.size()) {
        if (current == target)
            answer++;
        return;
    }
    DFS(current+numbers[index], index+1, numbers, target);
    DFS(current-numbers[index], index+1, numbers, target);
    return;
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, numbers, target);
    return answer;
}