from functools import cmp_to_key

def solution(numbers):
    answer = ''
    
    def cmp(x, y):
        if x + y > y + x:
            return -1
        elif x + y < y + x:
            return 1
        else:
            return 0
    
    numbers = list(map(str, numbers))
    
    sorted_numbers = sorted(numbers, key = cmp_to_key(cmp))
    
    result = ''.join(sorted_numbers)
    
    return '0' if result[0] == '0' else result