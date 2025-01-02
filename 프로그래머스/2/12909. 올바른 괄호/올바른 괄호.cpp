#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    
    int count = 0;
    
    for (const auto& i : s) {
        if (i == '(')
            count++;
        else if (i == ')')
            count--;
        
        if (count < 0)
            return false;
    }
    if (count == 0)
        return true;
    else 
        return false;
}