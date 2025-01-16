def solution(s):
    answer = True
    
    stack = []
    for c in s:
        if c == '(':
            stack.append(c)
        elif c == ')':
            if len(stack) == 0:
                return False
            del stack[-1]
    if len(stack) != 0:
        return False

    return True