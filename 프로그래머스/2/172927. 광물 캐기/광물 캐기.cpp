#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 10000;
    vector<string> pick;
    
    for (int i = 0; i < 3; i++) {
        while(picks[i] != 0) {
            if (i == 0) pick.push_back("diamond");
            else if (i == 1) pick.push_back("iron");
            else if (i == 2) pick.push_back("stone");
            picks[i]--;
        }
    }
    sort(pick.begin(), pick.end());
    
    do {
        int fatigue = 0;
        bool state = false;  //종료조건 변수
        for (int i = 0; i < pick.size(); i++) {
            int count = 0;
            for (int j = 5 * i; count < 5; count++) {
                if (j + count >= minerals.size()) {
                    state = true;
                    break;
                }
                
                if (pick[i] == "stone" && minerals[j + count] == "diamond")
                    fatigue += 25;
                else if (pick[i] == "stone" && minerals[j + count] == "iron")
                    fatigue += 5;
                else if (pick[i] == "iron" && minerals[j + count] == "diamond")
                    fatigue += 5;
                else 
                    fatigue += 1;
                
            }
            if(state) break;
        }
        
        if (answer > fatigue)
            answer = fatigue;

    }while(next_permutation(pick.begin(), pick.end()));
        
    return answer;
}