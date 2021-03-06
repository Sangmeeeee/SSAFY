# Info

문제 : [타일 채우기](https://www.acmicpc.net/problem)

알고리즘 종류 : DP

참조 url : 


# 1. 알고리즘 설명

### dp 배열 정의 및 초기화
일차원 dp 배열을 사용했으며  
`dp[i]`는 주어진 타일을 가지고 i까지 채우는 경우의 수를 저장한다.

문제에 따르면 주어지는 블록의 크기가 1x2, 2x1뿐이므로  
만약 `N`이 홀수로 주어진다면 경우의 수는 0이다.  
따라서 `dp` 배열은 0으로 초기화된 상태에서 짝수 인덱스만 채워주면 된다.  

### dp 배열 채우기

`N`이 2인 경우는 그림을 그려서 3가지 경우가 나오는 것을 확인할 수 있다.  
따라서 dp[2] = 3이다.

`N`이 4일 때부터는 **구간을 짝수 단위로 나누어서** 살펴볼 수 있다.  
3x4는 3x2 두 개로 나눠볼 수 있으며, 3x2를 채우는 경우의 수는 3가지이므로  
각 구간에 3개씩, 3*3 = 9가지가 된다.  
그리고 3x4에서의 **고유한 경우의 수가 2가지**이므로 이것까지 합치면 총 11가지가 된다.
```cpp
dp[4] = dp[4-2]*dp[2] + 2;
```

`N`이 6일 때도 마찬가지로 구간을 짝수 단위로 나눈다.

**(1) 3x6은 3x4와 3x2로 나눌 수 있다.**  
3x4를 채우는 경우의 수와 3x2를 채우는 경우의 수를 곱하면  
3x6을 채우는 경우의 수 일부를 구할 수 있다.

**(2) 3x6은 3x2와 3x4로 나눌 수 있다.**  
각 구간을 채우는 일반적인 경우를 (1)에서 구했으므로  
3x2를 채우는 경우의 수와 3x4의 고유한 경우의 수를 곱하여 특수한 경우를 구한다.  

(1), (2)에서 구한 경우의 수와 3x6에서의 고유한 경우의 수 2가지를 더한다.
```cpp
dp[6] = dp[6-2]*dp[2] + dp[6-4]*2 + 2;
```

이런 식으로 진행하면 dp 배열의 점화식을 다음과 같이 도출할 수 있다.
```cpp
dp[n] = dp[n-2]*dp[2] + dp[n-4]*2 + ... + dp[2]*2 + 2;
	= dp[n-2]*dp[2] + 2*(dp[n-4] + ... + dp[2]) + 2;
```

그림으로 확인하는 게 이해가 더 쉽다..!
![KakaoTalk_20220325_234225906](https://user-images.githubusercontent.com/57346428/160145439-558c5b88-2a73-459b-ba9b-2b3f293bf9ac.jpg)


# 2. 새로 배운 내용(코드 위주)
