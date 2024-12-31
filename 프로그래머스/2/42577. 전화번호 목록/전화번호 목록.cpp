#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> numbers;
    
    for (const auto& phone_number : phone_book) {
        numbers[phone_number]++;
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        string number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            number += phone_book[i][j];
            if (numbers[number] && number != phone_book[i])
                return false;
        }
    }

    return true;
}