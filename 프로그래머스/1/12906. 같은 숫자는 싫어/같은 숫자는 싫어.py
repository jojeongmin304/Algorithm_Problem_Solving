def solution(arr):
    answer = []
    pre = 0;
    for num in arr:
        if num in answer and pre == num:
            continue;
        else:
            answer.append(num);
            pre = num;

    return answer