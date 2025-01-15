#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(true) {
        if ((a-b == 1 && b%2) 
            || (b-a == 1 && a%2))
            break;

        if (a % 2) a = a/2 + 1;
        else a = a/2;

        if (b % 2) b = b/2 + 1;
        else b = b/2;

        answer++;    
    }
    return answer;
}