from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = deque()
    trucks = deque(truck_weights)
    nowWeight = 0
    
    for i in range (0, bridge_length):
        bridge.append(0)
    
    while len(bridge) != 0 or len(trucks) != 0:
        nowWeight -= bridge.popleft()
        
        if len(trucks) > 0:
            if len(bridge) < bridge_length and nowWeight + trucks[0] <= weight:
                bridge.append(trucks[0])
                nowWeight += trucks.popleft()
            else:
                bridge.append(0)
                
        answer += 1
    
    return answer