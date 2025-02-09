#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int count = lost.size();
    map<int, int> reserves;
    map<int, int> losts;
    
    for (int& i : lost)
        losts[i] = 1;
    for (int& i : reserve)
        reserves[i] = 1;
    
    for (auto& [key, value] : losts) {
        if (reserves[key] == 1) {
            losts[key] = 0;
            reserves[key] = 0;
            count--;
        }
    }
    for (auto& [key, value] : reserves) {
        if(reserves[key] == 1 && losts[key-1] == 1) {
            losts[key-1] = 0;
            reserves[key] = 0;
            count--;
        }
        else if(reserves[key] == 1 && losts[key+1] == 1) {
            losts[key+1] = 0;
            reserves[key] = 0;
            count--;
        }
    }
    int answer = n - count;
    return answer;
}