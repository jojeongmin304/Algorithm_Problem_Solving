#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int move = n - 1;
    
    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);  //커서 위아래 이동
        
        int ind = i + 1;
        while(ind < n) {
            if (name[ind] == 'A') ind++;
            else break;  //다음으로 바꿔야할 알파벳 위치 찾기
        }
        
        move = min(move, i + (n - ind) + min(i, n - ind));
    }
    return answer + move;
}