a# Info

문제 : [수들의 합 4](https://www.acmicpc.net/problem/2015)

알고리즘 종류 : 누적합, 맵

참조 url : https://www.crocus.co.kr/602


# 1. 알고리즘 설명

누적합 배열을 탐색하며 **1. 누적합**과 **2. 누적합의 횟수를 저장한 맵**을 이용하여 정답을 카운트 한다.

누적합 배열 `sum`을 앞에서부터 탐색하며 조건에 따라 정답을 업데이트하고, 맵 `m`의 해당 누적합 key에 대한 value를 1만큼 증가시킨다.

정답을 업데이트하는 경우는 다음의 두 가지이다.

1. 1~i까지의 합이 K인 경우
	- 즉, 누적합 배열 `sum[i]`가 K인 경우
	- `answer++;`
2. n~i까지의 합이 K인 경우
	- 누적합 배열에서는 `sum[i]-sum[j]`를 하면 j~i 구간의 합이 나온다.
	- i 이전까지의 누적합 중에서 `sum[i]-K`이 누적합이었던 횟수만큼 answer에 더한다.
	- 즉, `answer += m[sum[i]-K]`;

위 조건을 검사한 후 `m[sum[i]]`를 1만큼 증가시킨다.

![image](https://user-images.githubusercontent.com/57346428/157256876-18a3b2ba-3b09-47e9-82f3-f2e8f2b475ad.png)



# 2. 새로 배운 내용(코드 위주)
