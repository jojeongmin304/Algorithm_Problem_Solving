def solution(answers):
    answer = []
    
    answerOne = [1, 2, 3, 4, 5]
    countOne = 0
    
    answerTwo = [2, 1, 2, 3, 2, 4, 2, 5]
    countTwo = 0
    
    answerThree = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    countThree = 0
    
    for i in range(0, len(answers)):
        if (answers[i] == answerOne[i % 5]): countOne += 1;
        if (answers[i] == answerTwo[i % 8]): countTwo += 1;
        if (answers[i] == answerThree[i % 10]): countThree += 1; 
    
    temp = []
    temp.append(countOne);
    temp.append(countTwo);
    temp.append(countThree);
    maxScore = max(temp)
    
    for i in range(0,3):
        if (maxScore == temp[i]):
            answer.append(i+1)
        
    return answer