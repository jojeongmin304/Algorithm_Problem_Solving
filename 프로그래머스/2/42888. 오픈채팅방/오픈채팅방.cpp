#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> users;
    
    for (const auto& str : record) {
        string command = "";
        string ID = "";
        string nickname = "";
        int i = 0;
        while(str[i] != ' ') {
            command += str[i];
            i++;
        }
        i++;
        while(str[i] != ' ') {
            ID += str[i];
            i++;
        }
        i++;
        while(i < str.size()) {
            nickname += str[i];
            i++;
        }
        if (command == "Enter")
            users[ID] = nickname;
        else if (command == "Change")
            users[ID] = nickname;
    }
    for (const auto& str : record) {
        string command = "";
        string ID = "";
        int i = 0;
        while(str[i] != ' ') {
            command += str[i];
            i++;
        }
        i++;
        if (command == "Leave") {
            while(i < str.size()) {
                ID += str[i];
                i++;
            }
        }
        else if (command == "Enter") {
            while(str[i] != ' ') {
            ID += str[i];
            i++;
            }
        }
        if (command == "Enter")
            answer.push_back(users[ID]+"님이 들어왔습니다.");
        else if(command == "Leave")
            answer.push_back(users[ID]+"님이 나갔습니다.");
    }
    return answer;
}