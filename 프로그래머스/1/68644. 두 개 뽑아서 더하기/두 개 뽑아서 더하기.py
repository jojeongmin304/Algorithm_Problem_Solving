def solution(numbers):
    answer = []
    a = set()
    numbers.sort()
    for i in range (0, len(numbers)-1):
        for j in range (i+1, len(numbers)):
            a.add(numbers[i] + numbers[j])
    answer = list(a)
    answer.sort()
    return answer