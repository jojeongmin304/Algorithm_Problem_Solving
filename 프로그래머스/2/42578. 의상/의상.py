def solution(clothes):
    answer = 1
    d = dict()
    for cloth in clothes:
        if cloth[1] in d:
            d[cloth[1]] += 1
        else:
            d[cloth[1]] = 1
            
    for num in d.values():
        answer *= num+1
    
    return answer-1