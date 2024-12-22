#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = 1;
    int height = yellow / width;  //노란색의 가로세로
    
    while(true) {
        if (!(yellow % width)) {
            height = yellow / width;
            
            if (width >= height && (width+2)*(height+2) - yellow == brown)
                break;
        }
        width++;
    }
        
    answer.push_back(width+2);
    answer.push_back(height+2);
    
    return answer;
}