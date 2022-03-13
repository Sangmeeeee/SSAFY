# Info

  

문제 : [박스 채우기](https://www.acmicpc.net/problem/1493)

알고리즘 종류 : 분할 정복

참조 url : https://excited-hyun.tistory.com/114

  

# 알고리즘 설명
일단 현재 박스에 넣을 수 있는 가장 큰 큐브를 찾아서 넣는데 이 때 남은 공간을 세 부분으로 나눌 수 있다.  

<img width=380 src="https://user-images.githubusercontent.com/55791128/157489435-d2feda80-3be8-4653-af11-689926e15f60.jpg"/>  

세 부분에 대해서 각각 다시 가장 큰 큐브를 찾아 넣는 것을 반복한다.  
큐브를 넣고 나서 전체 부피에서 해당 큐브의 부피를 빼준다.  
모든 계산이 끝나고 남은 전체 부피가 0이 아니면 박스를 채울 수 없는 것이기 때문에 -1을 출력한다. 


# 새로 배운 내용
현재 직육면체에 넣을 수 있는 가장 큰 정육면체를 찾을 때 다음과 같이 코드를 짰다.
```c++
	// 넣을 수 있는 가장 큰 정육면체 찾기
	int idx = -1, side = 0;
	for (int i = max_i; i >= 0; i--) {
		if (cube[i].second == 0)
			continue;

		side = cube[i].first;
		if (side <= l && side <= w && side <= h) {
			cube[i].second--;
			ans++;
			idx = i;
			break;
		}
	}
```
문제가 되는 부분은 pow()인데 이게 직육면체 크기가 작으면 문제가 없지만 크기가 커지면 재귀 호출 횟수도 기하급수적으로 증가해서 pow() 연산 횟수도 그만큼 증가하다보니 시간 초과가 나게 된다.  

```c++
	for (int i = 0; i < N; i++) {		
		cin >> A >> B;
		cube[A] = { (int)pow(2, A), B };
	}
```
그래서 int cube[]를 pair<int, int> cube[]로 선언하고 {pow(2, i), 갯수}를 저장하는 걸로 시간 초과를 해결했다.

