def solution(id_list, report, k):
    answer = [0]*len(id_list)
    dict = {name : 0 for name in id_list}
    
    for case in set(report):
        ing, ed = case.split()
        dict[ed] += 1
    
    for case in set(report):
        ing, ed = case.split()
        if dict[ed] >= k: answer[id_list.index(ing)] += 1
            
    
    return answer