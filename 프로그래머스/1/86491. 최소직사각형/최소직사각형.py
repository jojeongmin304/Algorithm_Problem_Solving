def solution(sizes):
    answer = 0
    biggerMax = 0;
    smallerMax = 0;
    for card in sizes:
        bigger = max(card);
        smaller = min(card);
        if bigger > biggerMax:
            biggerMax = bigger;
        if smaller > smallerMax:
            smallerMax = smaller;
    answer = biggerMax * smallerMax;

    return answer