def solution(phone_book):
    a = set(phone_book)
    
    for number in phone_book:
        temp = "";
        for num in number:
            temp += num
            if temp == number: break
            if temp in a:
                return False
    return True