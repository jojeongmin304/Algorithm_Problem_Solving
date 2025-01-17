def solution(prices):
    answer = []
    n = len(prices)
    for i in range (0, n-1):
        count = 0
        for j in range(i+1, n):
            count += 1
            if prices[i] > prices[j]:
                break
        answer.append(count)
    answer.append(0)
    return answer