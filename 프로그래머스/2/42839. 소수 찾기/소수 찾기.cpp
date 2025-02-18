#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isPrime(int a) {
    if (a == 0 || a == 1)
        return false;
    
    for (int i = 2; i < a; i++) {
        if (a % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    unordered_set<int> set;
    
    do {
        string str = "";
        for (int i = 0; i < numbers.size(); i++) {
            str += numbers[i];
            int num = stoi(str);
            if (isPrime(num))
                set.insert(num);
        }
        
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    
    return set.size();
}