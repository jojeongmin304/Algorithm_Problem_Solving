def solution(clothes):
    answer = 1
    dict = {}
    for cloth in clothes:
        if cloth[1] not in dict:
            dict[cloth[1]] = 1
        else:
            dict[cloth[1]] += 1
    
    for val in dict.values():
        answer *= val+1
    
    return answer-1