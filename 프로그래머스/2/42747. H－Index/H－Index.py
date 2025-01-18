def solution(citations):
    answer = 0
    citations.sort()
    citations.reverse()
    n = len(citations)
    for i in range (0, n):
        if citations[i] < i+1:
            break
        answer = i+1
        
    return answer