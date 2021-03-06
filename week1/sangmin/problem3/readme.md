문제 : [괄호 제거](https://www.acmicpc.net/problem/2800)

알고리즘 종류 : 문자열

참조 url :

# 1. 알고리즘 설명

<img width="724" alt="스크린샷 2022-01-26 오후 7 20 55" src="https://user-images.githubusercontent.com/24482602/151145895-2dca813c-9a81-4e8e-85ae-acfa8ee4e8ed.png">

무자비한 메모리 초과 문구와 함께 생각보다 오래걸렸다.

분명히 로컬에서는 잘 돌아가는데 왜 안될까라고 계속 생각해보다가 문제는 solve 메소드의 for문을 통해 괄호쌍의 idx를 저장한 배열을 도는 부분이었다.

이 문제는 짝지어진 괄호들의 부분집합들의 개수만큼 문자열이 나올 수 있다. 물론 (((0 + 1))) 같은 특이한 경우도 나올 수 있지만 이는 Collection의 Map이

해결해줄것이다.

내가 이전에 짠 코드는 

```java
    for(int i = 0; i < count; i++){
        { 집합을 돌며 괄호부분을 제외하고 문자열을 생성하는 logic }
    }
```
인데 이렇게 되면

만약 3개의 괄호가 존재한다 할때 재귀함수를 돌며 제거되는 괄호를 적어보자면

    (1) -> (1, 2) -> (1, 2, 3) -> (1, 3)
    (2) -> (2, 1) -> (2, 1, 3) -> (2, 3)
    (3) -> (3, 1) -> (3, 1, 2) -> (3, 2)

3개의 괄호만 존재한다 해도 불필요한 연산이 5개나 존재한다. 따라서 이를 줄이기 위해선

n번째 괄호를 무조건 포함하는 집합을 구할때 n-1번째 괄호의 집합(n-1번째 괄호를 포함하던 안하던)은 빼줘야한다.

    (1) -> (1, 2) -> (1, 2, 3) -> (1, 3)
    (2) -> (2, 3) 
    (3)

n번째 괄호를 계산했다는 변수를 level로 따로 두어 level에서 부터 집합을 돌면서 불필요한 연산을 줄였다.

```java
    for(int i = level; i < count; i++){
        { 집합을 돌며 괄호부분을 제외하고 문자열을 생성하는 logic }
    }
```

이렇게하면 3개의 괄호를 상대로 7개의 문자열이 나오고 TreeSet을 이용해서 문자열 순으로 출력해준다.

만약 (((0 + 1))) 같은 특수한 괄호도 결국 연산은 7번을 하겠지만 Map의 특성상 답은 하나로 나오게 된다.

# 2. 새로 배운 내용

만약 내가 원래 작성했던 코드대로 시간 복잡도를 계산한다면 n!의 시간복잡도가 나오기 때문에 사용하지 못하는 로직인데다가 당연히 그만큼 함수의 호출도 많아지고

문자열도 많이 생성되기 때문에 메모리 초과가 나는건 당연했다. 다음부터는 생각하고 로직을 짜야겠다.