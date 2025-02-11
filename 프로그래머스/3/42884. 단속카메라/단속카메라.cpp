#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] < b[0];
    return false;   
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> check(routes.size(), 0);  
    sort(routes.begin(), routes.end(), cmp);
    int count = 0;
    
    for (int i = 0; i < routes.size(); i++) {
        if (check[i] == 0) {
            int cam = routes[i][1];
            count++;
            check[i]++;
            for (int j = i+1; j < routes.size(); j++) {
                if (check[j] == 0 && routes[j][0] <= cam)
                    check[j]++;
            }
        }
    }
    answer = count;
    return answer;
}