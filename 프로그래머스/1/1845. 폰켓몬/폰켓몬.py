def solution(nums):
    a = set()
    for num in nums:
        a.add(num)
    
    if len(a) < len(nums)/2:
        return len(a)
    else:
        return len(nums)/2