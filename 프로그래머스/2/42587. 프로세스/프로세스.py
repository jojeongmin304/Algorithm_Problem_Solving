def solution(priorities, location):
    answer = 1
    while True:
        if priorities[0] == max(priorities):
            if location == 0:
                break
            del priorities[0]
            location -= 1
            answer += 1
        else:
            priorities.append(priorities[0])
            del priorities[0]
            if location == 0:
                location += len(priorities)-1
            else:
                location -= 1
    return answer