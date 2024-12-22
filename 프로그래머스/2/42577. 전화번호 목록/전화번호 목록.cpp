#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> numbers;
    
    for (auto& number : phone_book) {
        numbers[number]++;
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if (numbers[phone_number] && phone_number != phone_book[i])
                return false;
        }
    }
    return true;
}