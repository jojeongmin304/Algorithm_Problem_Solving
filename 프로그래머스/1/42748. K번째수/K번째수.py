def solution(array, commands):
    answer = []
    for nums in commands:
        temp = array[nums[0]-1 : nums[1]]
        temp.sort()
        answer.append(temp[nums[2]-1])
    return answer