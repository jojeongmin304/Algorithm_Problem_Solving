#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> ref;
    unordered_map<string, int> money;
    
    for (int i = 0; i < enroll.size(); i++) {
        ref[enroll[i]] = referral[i];
    }
    for (int i = 0; i < enroll.size(); i++) {
        money[enroll[i]] = 0;
    }
    
    for (int i = 0; i < seller.size(); i++) {
        string name = seller[i];
        int cash = amount[i] * 100;
        while(name != "-" && cash > 0) {
            int distribute = cash / 10;
            money[name] += cash - distribute;
            name = ref[name];
            cash = distribute;
        }
    }
    
    for (const auto& name : enroll) {
        answer.push_back(money[name]);
    }
    
    return answer;
}