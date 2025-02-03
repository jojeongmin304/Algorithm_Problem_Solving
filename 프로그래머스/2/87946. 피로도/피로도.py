import itertools

def solution(k, dungeons):
    answer = -1
    for case in list(itertools.permutations(dungeons)):
        count = 0
        fatigue = k
        for dungeon in case:
            if fatigue >= dungeon[0]:
                fatigue -= dungeon[1]
                count += 1
            else:
                break
        if count > answer:
            answer = count
                
            
    return answer