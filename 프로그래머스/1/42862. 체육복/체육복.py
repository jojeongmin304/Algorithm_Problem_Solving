def solution(n, lost, reserve):
    answer = n - len(lost)
    lost.sort()
    
    for student in lost[:]:
        if student in reserve:
            reserve.remove(student)
            lost.remove(student)
            answer += 1
    
    for student in lost[:]:
        if student-1 in reserve:
            reserve.remove(student-1)
            answer += 1
        elif student+1 in reserve:
            reserve.remove(student+1)
            answer += 1
            
    return answer