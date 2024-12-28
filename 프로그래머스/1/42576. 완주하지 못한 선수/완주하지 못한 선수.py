def solution(participant, completion):
    answer = ''
    d = dict();
    for name in completion:
        if name in d:
            d[name] += 1; 
        else:
            d[name] = 1;
        
    for name in participant:  
        if name in d and d[name] > 0:
            d[name] -= 1;
        else :
            return name;