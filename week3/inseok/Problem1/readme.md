문제 : [카드 정렬하기] ([url](https://www.acmicpc.net/problem/1715))

알고리즘 종류 : 우선순위큐(힙)

참조 url : ([url](https://coding-factory.tistory.com/603))

# 1. 알고리즘 설명(로직위주)

## 문제 이해

카드 더하기 문제들이 힙문제가 많은건가? 기계적으로 힙 문제 풀어야지 하고 푸는게 아니라 왜 힙을 써야 하는지 아는게 중요하다. 문제 자체는 쉬웠다.

일단! 내가 생각할 땐, 여러번 소팅 해야할 경우에는 PriorityQueue(힙) 을 사용 하는것이 유리할때가 많다고 생각한다. (다른 분들의 생각도 좀 들어볼 필요가 있는듯)

일단 삽입에 log(n) , 삭제에 log(n) 이라는 시간이 걸리고, 정렬은 자동으로 된다는 특성을 가지고 있다. 

## 로직

일단 받아올때 부터 PriorityQueue<Integer>priorityQueue 로 생성해준다. 이를 입력받는 숫자를 모두 add해주어 힙상태를 만들어준다. 

PriorityQueue의 사이즈가 1이 될때 까지 while 문을 돌면서 두 숫자를 빼내어 더한 숫자를 total이라는 숫자에 더해주고, 그 더한 숫자를 다시 PriorityQueue에 삽입 해준다(알아서 정렬 되서 들어가게 된다. 이 포인트가 힙을 쓰는 이유라 생각...)

반복문을 마치면 total 이 출력된다.

# 2. 새로 배운 내용(코드위주)

## PriorityQueue큐 사용법

### 간단한 예제...(사용법은 주석보고 이해)

```java

import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
				priorityQueue.add(1);
				priorityQueue.offer(2);
				priorityQueue.add(3);
				priorityQueue.add(4);

				priorityQueue.poll();
				priorityQueue.remove();
				priorityQueue.clear();
    }
}
```

딱히 어려운 건 없었고, 나중에 내가 잘 쓸 수 있을지와 힙 자체에 대한 고민을 공부 해보면 좋겠다.(복습겸)