# Info

문제 : [두 용액](https://www.acmicpc.net/problem/2470)

알고리즘 종류 : 투포인터

참조 url :


# 1. 알고리즘 설명

1. 입력 받은 배열을 **오름차순 정렬**한다.
2. 양 끝(0, N-1)에 포인터를 둔다.
3. `left`번째 수와 `right`번째 수의 합이 현재의 최솟값보다 작다면 정답을 업데이트한다.
4. 다음 값을 계산하여 포인터를 업데이트시킨다.
	- `val1` = (`left`번째 수 + `right-1`번째 수)의 절댓값
	- `val2` = (`left+1`번째 수 + `right`번째 수)의 절댓값
	- `val1`이 `val2`보다 작다면 `right`를 1 감소시킨다.
	- `val2`가 `val1	`보다 작거나 같다면 `left`를 1 증가시킨다.
5. `left`와 `right`가 같아질 때까지 3~4번을 반복한다.

![KakaoTalk_20220315_031600579](https://user-images.githubusercontent.com/57346428/158236496-04df8a43-9106-4a95-9b8e-cc2fede39a12.jpg)


# 2. 새로 배운 내용(코드 위주)
