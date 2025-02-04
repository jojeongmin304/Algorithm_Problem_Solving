#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int one = 0;
    int two = 0;
    int three = 0;
    vector<int> temp(3, 0);
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == first[i % 5]) temp[0]++;
        if (answers[i] == second[i % 8]) temp[1]++;
        if (answers[i] == third[i % 10]) temp[2]++;
    }
    
    int max = *max_element(temp.begin(), temp.end());
    
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == max)
            answer.push_back(i+1);
    }
    
    return answer;
}