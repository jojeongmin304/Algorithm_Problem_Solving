def solution(schedules, timelogs, startday):
    answer = 0
    for i in range(0, len(schedules)):
        safetime = schedules[i] + 10
        if safetime % 100 >= 60:
            safetime += 40
        state = True
        day = startday
        
        for time in timelogs[i]:
            if day == 6 or day == 7:
                day += 1
                if day == 8:
                    day = 1
                continue
            
            if safetime < time:
                state = False
                break
                
            else: day += 1
            
        if state == True : answer += 1
    
    return answer