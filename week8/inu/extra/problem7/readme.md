# Info

  

문제 : [다이어트](https://www.acmicpc.net/problem/1484)

알고리즘 종류 : 투포인터

참조 url : 

  

# 알고리즘 설명
현재 몸무게를 j, 과거 몸무게를 i라고 하면 G = j * j - i * i이므로 j * j는 적어도 G보다는 커야한다.  
그래서 먼저 이를 만족하는 j를 먼저 찾아야 한다.
``` c++
	int n = 1;
	while (n * n < G) n++;
	j = n;
```

그 다음에 j * j - i * i == G를 만족하는 i, j를 찾아나가면 된다.
``` c++
	while (i < j) {
		if (j * j - i * i <= G) {
			if (j * j - i * i == G)
				weight.push_back(j);
			j++;
		}
		else
			i++;
	}
```
현재 몸무게와 과거 몸무게의 차이가 G보다 작으면 j를 증가시키고 G보다 크면 i를 증가시킨다.  
이를 반복하다보면 i == j - 1일 때 j * j - i * i가 G보다 커지는 때가 경우가 있기 때문에 i == j가 되고 while문이 종료된다.
# 새로 배운 내용

