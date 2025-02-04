def solution(arr):
    answer = []
    for num in arr:
        if len(answer) == 0 or num != answer[-1]:
            answer.append(num)
    return answer