#https://programmers.co.kr/learn/courses/30/lessons/42626#
#프로그래머스-더 맵게
import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville[0]<K:
        heapq.heappush(scoville,heapq.heappop(scoville) + (heapq.heappop(scoville)*2))
        answer+=1
        if len(scoville)<=1 and scoville[0]<K:
            return -1
    return answer