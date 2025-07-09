#include <unordered_map>
#include <vector>
#include <algorithm>
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        unordered_map<char, vector<pair<int, int>>> um;
        for (vector<int>& c : costs) {
            char where;
            int cheap= 0, expensive = 0; //변수초기화

            //싼곳지정
            if (c[0] < c[1]) {cheap = c[0]; expensive = c[1]; where = 'A';}
            else {cheap = c[1]; expensive = c[0]; where = 'B';}

            int moneyGap = expensive - cheap;
            um[where].push_back({cheap, moneyGap});
        }

        char longer, shorter;
        if (um['A'].size() > um['B'].size()) {longer = 'A'; shorter = 'B'; }
        else {longer = 'B'; shorter = 'A';}

        int need = (um[longer].size() - um[shorter].size()) / 2;
        int total = 0;

        for (pair<int, int>& p : um[shorter])
            total += p.first;
        
        sort(um[longer].begin(), um[longer].end(), cmp);
        for (pair<int, int>& p : um[longer]) {
            if (need > 0) {
                total += p.second;
                need--;
            }
            total += p.first;
        }

        return total;
    }
};