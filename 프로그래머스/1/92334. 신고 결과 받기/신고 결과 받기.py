def solution(id_list, report, k):
    answer = [0] * len(id_list)  ##answer초기화
    stop = {x : 0 for x in id_list}  ##stop dict초기화
    
    for r in set(report):
        stop[r.split()[1]] += 1
    
    for r in set(report):
        if stop[r.split()[1]] >= k:
            answer[id_list.index(r.split()[0])] += 1
    
    return answer