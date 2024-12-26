def solution(nums):
    answer = 0
    answer = len(set(nums));
    if (answer >= len(nums)/2):
        return len(nums)/2;
    return answer;