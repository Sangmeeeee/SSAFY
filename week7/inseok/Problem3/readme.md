문제 : [](https://www.acmicpc.net/problem/14891)[[박스 채우기]](https://www.acmicpc.net/problem/1493)

알고리즘 종류 : 분할정복. 

참조 url : [url](https://dhpark-blog.tistory.com/entry/BOJ-1493-%EB%B0%95%EC%8A%A4-%EC%B1%84%EC%9A%B0%EA%B8%B0)

# 1. 알고리즘 설명(로직위주)

## 문제 이해

### 이번에 잘 푼거 같은데 뭔가 부족한가보다.

한꺼번에 계산하도록 잘 계산 해준거 같은데 뭔가 부족한지 잘 되지가 않는다.

## 로직

### fillSpace 함수

파라미터로 length,width height를 받는 함수다.

제일 큰 width 로 들어갈 박스의 사이즈를 정하고, 길이들을 boxWidth로 모든 변을 나누어 변마다 박스가 들어가는 갯수(xs,ys,zs) 와 박스의 갯수를 구한다.

그거에 맞게 fillSpace 를 세번 다시 불러서 fillSpace를 해준다. 

# 2. 새로 배운 내용(코드위주)