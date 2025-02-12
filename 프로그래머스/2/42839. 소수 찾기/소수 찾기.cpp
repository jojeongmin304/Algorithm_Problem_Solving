#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> temp;
    set<int> a{};
    
    sort(numbers.begin(), numbers.end());
    do {
        string str = "";
        for (const auto& c : numbers) {
            str += c;
            if (isPrime(stoi(str)))
                a.insert(stoi(str));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return a.size();
}