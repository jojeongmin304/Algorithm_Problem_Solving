def solution(phone_book):
    answer = True
    a = set(phone_book)
    
    for num in phone_book:
        str = ""
        for t in num:
            str += t
            if str == num: break
            if str in a:
                return False
    
    return answer