#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> result;
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            result.insert(sum);
        }
    }
    vector<int> answer(result.begin(), result.end());
    
    return answer;
}