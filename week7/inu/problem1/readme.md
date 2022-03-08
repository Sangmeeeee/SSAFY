# Info

  

문제 : [소형 기관차](https://www.acmicpc.net/problem/2616)

알고리즘 종류 : 누적 합, 다이나믹 프로그래밍

참조 url : https://hees-dev.tistory.com/58

  

# 알고리즘 설명
N : 총 객차 수, M : 1개의 소형 기관차가 끌 수 있는 객차 수 
```c++
for (int i = 1; i <= 3; i++) {
		for (int j = i * M; j <= N; j++) {
			maxPerson[i][j] = max(maxPerson[i][j - 1],
				maxPerson[i - 1][j - M] + (person[j] - person[j - M]));
		}
	}
```
- maxPerson[i][j]: i개의 소형 기관차를 가지고 j번째 객차까지 고려했을 때 운반 가능한 최대 승객 수  
- j는 i*M부터 시작해야 i개의 소형 기관차가 각각 M개를 끌 수 있음

maxPerson[i][j]는 두 개의 값을 비교해서 더 큰 값으로 결정된다.
1. maxPerson[i][j - 1] 
    - 현재 객차를 고려하지 않고 이전 객차까지만 고려했을 때의 승객 수
2. maxPerson[i - 1][j - M] + (person[j] - person[j - M])
    - 현재 객차(j)를 고려하게 되면 (j-M+1)번째부터 j번째 객차까지 i번째 소형 기관차가 끌게 된다.
    - 그렇다면 (i - 1)개의 소형 기관차는 (j - M)번째 객차까지만 고려해서 최대 승객 수를 계산하게 되는데 이 값은 이미 계산돼서 maxPerson[i - 1][j - M]에 저장된 상태다.
    - 따라서 maxPerson[i - 1][j - M]에 (j-M+1)번째부터 j번째 객차까지의 승객 수를 더하면 현재 객차까지 고려했을 때 최대 승객 수를 구할 수 있다.

위 과정을 반복하면 maxPerson[3][N]에 문제에서 요구하는 최댓값이 저장된다.


# 새로 배운 내용
dp문제를 거의 안 풀어봐서 결국 다른 사람들의 코드를 참고했다.
참 봐도봐도 어렵다...