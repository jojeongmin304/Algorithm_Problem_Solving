#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        int count = -1;
        for (int j = i; j < prices.size(); j++) {
            count++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(count);
    }
    return answer;
}