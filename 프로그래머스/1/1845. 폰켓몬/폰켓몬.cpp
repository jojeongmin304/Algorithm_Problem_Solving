#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> types(200001, 0);  //1번 인덱싱
    
    for (int& i : nums) {
        types[i]++;  //종류번호를 인덱스로 사용
    }
    
    int count = 0; //종류최대값
    for (int& type: types) {
        if (type != 0)
            count++;
        if (count == nums.size()/2)
            return count;
    }
    
    answer = count;
    return answer;
}