def solution(array, commands):
    answer = [];
    
    for command in commands:
        temp = [];
        for i in range (command[0]-1, command[1]):
            temp.append(array[i]);
        temp.sort();
        answer.append(temp[command[2]-1]);
            
    return answer