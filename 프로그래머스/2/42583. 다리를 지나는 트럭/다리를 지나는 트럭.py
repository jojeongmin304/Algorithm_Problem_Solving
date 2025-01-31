from collections import deque

def solution(bridge_length, weight, truck_weights):
    bridgeQ = deque([0] * bridge_length)
    waitQ = deque(truck_weights)
    now = 0
    answer = 0
    
    while waitQ or now > 0:
        now -= bridgeQ.popleft()
        
        if waitQ and now + waitQ[0] <= weight:
            truck = waitQ.popleft()
            bridgeQ.append(truck)
            now += truck
        else:
            bridgeQ.append(0)

        answer += 1
        
    return answer