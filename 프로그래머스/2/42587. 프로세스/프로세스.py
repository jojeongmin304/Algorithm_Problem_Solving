def solution(priorities, location):
    answer = 0
    while True:
        if priorities[0] == max(priorities):
            answer += 1
            if location == 0:
                return answer
            else:
                priorities.remove(priorities[0])
                location -= 1
        else:
            priorities.append(priorities[0])
            priorities.remove(priorities[0])
            if location == 0:
                location += len(priorities)-1
            else:
                location -= 1