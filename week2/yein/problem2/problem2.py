#https://programmers.co.kr/learn/courses/30/lessons/42583
#프로그래머스-다리를 지나는 트럭

from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge_truck = deque([0]*bridge_length)
    sum_weight = 0
    
    while bridge_truck:
        answer+=1
        sum_weight-=bridge_truck.popleft()
        if truck_weights:
            if sum_weight+truck_weights[0]<=weight: 
                bridge_truck.append(truck_weights.pop(0))
                sum_weight+=bridge_truck[-1]
            else: bridge_truck.append(0)
        
    return answer