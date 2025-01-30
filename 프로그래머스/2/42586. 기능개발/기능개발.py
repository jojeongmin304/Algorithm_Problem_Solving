import math

def solution(progresses, speeds):
    answer = []
    for i in range(0, len(speeds)):
        left = (99-progresses[i]) / speeds[i] + 1
        progresses[i] = math.floor(left)
        
    start = progresses[0]
    count = 0
    for i in range(0, len(speeds)):
        if (progresses[i] > start):
            answer.append(count)
            count = 0
            start = progresses[i]
        count += 1
    answer.append(count)
    return answer