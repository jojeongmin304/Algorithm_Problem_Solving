from math import sqrt
from itertools import permutations

def check(n):
    if n < 2:
        return False
    
    for i in range (2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True

def solution(numbers):
    answer = []
    numbers = list(numbers)
    temp = []
    
    for i in range(1, len(numbers) + 1):
        temp += list(permutations(numbers, i))
    num = [int(''.join(t)) for t in temp]
    
    for i in num:
        if check(i):
            answer.append(i)
    
    return len(set(answer))