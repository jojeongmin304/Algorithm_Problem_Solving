def solution(participant, completion):
    answer = ''
    a = dict()
    for name in completion:
        if name in a:
            a[name] += 1
        else:
            a[name] = 1
    for name in participant:
        if name not in a or a[name] == 0:
            return name
        else:
            a[name] -= 1
    return participant[-1]