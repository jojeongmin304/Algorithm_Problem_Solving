#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int finish = 0;
    int count = 0;
    
    while(finish < progresses.size()) {
        for (int i = finish; i < progresses.size(); i++) {
        
            progresses[i] += speeds[i];
        
            if (progresses[i] >= 100 && i == (finish + count))
                count++;
        
            if (i == progresses.size() - 1) {
                finish += count;
                if (count != 0)
                    answer.push_back(count);
                count = 0;
            } 
        }
    }
    
    return answer;
}