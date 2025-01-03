#include <string>
#include <vector>

using namespace std;

int dfs(string a, int& count, string word) {
    string aeiou = "AEIOU";
    
    if (a == word)
        return count;
    
    if (a.size() >= 5)
        return -1;
    
    for (int i = 0; i < 5; i++) {
        count++;
        int result = dfs(a + aeiou[i], count, word);
        if (result != -1)
            return result;
    }
    return -1;
}

int solution(string word) {
    int answer = 0;
    return dfs("", answer, word);
}