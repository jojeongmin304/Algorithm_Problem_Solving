#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int width = 1;
    int height = yellow / width;
    while (true) {
        if (yellow % width == 0){
            height = yellow / width;
            
            if (width >= height and (width+2)*(height+2) == brown+yellow)
            break;
        }
        width++;
    }
    return {width+2, height+2};
}