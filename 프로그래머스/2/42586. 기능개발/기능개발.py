def solution(progresses, speeds):
    import math
    answer = []
    n = len(progresses)
    
    for i in range(0, n):
        progresses[i] = math.ceil((100-progresses[i]) / speeds[i])
    
    max = progresses[0]
    count = 1
    for i in range(1, n):
        if max < progresses[i]:
            max = progresses[i]
            answer.append(count)
            count = 1
        else:
            count += 1
    answer.append(count)
            
    return answer