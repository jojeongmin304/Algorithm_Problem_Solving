from functools import cmp_to_key

def cmp(a, b):
    if a + b > b + a:
        return -1
    elif a + b < b + a:
        return 1
    else:
        return 0

def solution(numbers):
    answer = ''
    strnums = list(map(str, numbers))
    sortedstrnums = sorted(strnums, key = cmp_to_key(cmp))
    
    for t in sortedstrnums:
        answer += t
    
    return '0' if answer[0] == '0' else answer