#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> um;
    
    um[words[0]]++;
    for (int i = 1; i < words.size(); i++) {
        if (words[i-1].back() != words[i].front() || um[words[i]] != 0) {
            int quo = (i+1) / n;
            int mod = (i+1) % n;
            if (mod == 0) return {n, quo};
            else return {mod, quo+1};
        }
        else
            um[words[i]]++;
    }
    return {0, 0};
}