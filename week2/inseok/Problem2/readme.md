문제 : [다리를 지나는 트럭] ([url](https://programmers.co.kr/learn/courses/30/lessons/42583?language=java))

알고리즘 종류 : 큐

참조 url : 

# 1. 알고리즘 설명(로직위주)

## 문제 이해

트럭이 다리에 올라가는 문제.. 예전에 본적 있는듯한 익숙한 문제

큐 문제 라서 큐로 풀어야 하는것도 있지만 왜 풀어야할까? 들어가서 나가는건 첨에 들어갔던 녀석이 나가는거 같아보이니 FILO 로 보이기에 큐...

하튼 큐로 문제 풀어야겠다고 생각했음. 근데 자바에서는 Queue를 한번도 안써봤다는거..

Queue Interface 를 이용한 LinkedList 클래스이다. (다형성,새로 배운내용에 써 놓자.) 일단 중요한 method는 offer ,poll 이렇게 되겠다.

## 로직

queue 를 bridge_length 만큼 미리 0으로 넣어주었다. 반복문에서 poll, offer, 탈출체크 이렇게 세개를 반복 했다. 

poll 할때 다리위에 올려진 무게인 bWeight에서 poll 되는 녀석만큼 뺐다.

offer를 할때 우리가 보기에는 트럭이 들어가냐, 안들어가냐 이지만, 트럭weight가 들어가냐, 0 이 들어가냐 로 보았다. 그래서 (총무게 + 들어가려는 트럭무게) ≤ (제한무게) 이면 트럭weight를 offer, 아니라면 0을 offer해줬다.

반복문을 한번 돌때 마다 시간이 1초 지나는거라 answer++  해줬다.

탈출 조건은 truck_weights의 index 를 모두 탐색 한 이후(truck_weight.length == index)에 반복문을 탈출 해줬다. 

### 

# 2. 새로 배운 내용(코드위주)

## 큐 사용법

### 간단한 예제...(사용법은 주석보고 이해)

```java
import java.util.LinkedList;
import java.util.Queue;

public static int solution() {
	  Queue<Integer> q =new LinkedList<>();//offer, poll, remove
		int num;
	  q.offer(1);// -> 1 ->
		q.offer(2);// -> 2 -> 1 ->
		q.offer(5);// -> 5 -> 2 -> 1 ->
		num = q.poll();//1
		num = q.poll();//2
		num = q.poll();//5
}
```

### Queue<Integer>q = new LinkedList<>();

Queue 인터페이스 참조변수 q를 생성 하여 클래스를 컨트롤 할거고, LinkedList 클래스인스턴스를 만들었다.

여기서 조금 이질감 느꼈던것은 

1. 왼쪽 부분인 Queue인터페이스 q 라는 참조변수를 만드는것.
    1. 인터페이스 객체 생성이 안 되는 거지, 인터페이스 타입의 참조변수 만드는 데는 아무런 문제가 없다.

궁금증을 느꼈던 부분도 있다.(이렇게 파고 들어 가는게 좋은 건지 모르겠는데.. 성향이 그런가봐 )

1. LinkedList 는 어떻게 Queue를 인터페이스로 받을 수 있지? LinkedList들어갔는데 implement Queue 가 안되어있는데?
    1. 정답은 다형성이다.(그 다형성이 첨에 직관적으로 이해가 안되어서 그런거지..)
    2. 아래 사진은 java.util 의 인터페이스(하늘색) 와 클래스(파랑)의 관계를 볼수 있다. 인터페이스를 배울때 “기능 구현의 강제” 라는 것을 배웠다. 이렇게  LinkedList는 deque,List 등을 implement받고 있는데 여기서 deque가 queue를 상속받아 만들어진 녀석이라 메서드를 모두 오버라이딩 하고 있더라!
        
        ![Collection interface class 관계도.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d45d0c7f-14e0-4637-b23f-cc3cd98f1432/Collection_interface_class_관계도.png)
        
        참조 : [https://www.falkhausen.de/Java-8/java.util/Collection-Hierarchy.html](https://www.falkhausen.de/Java-8/java.util/Collection-Hierarchy.html)
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/367faeb4-d52d-4bda-a900-7502de601a94/Untitled.png)
        
    3. 이렇게 인터페이스들도 서로 상속을 하고, 클래스도 클래스끼리 상속을 하다가 필요한 기능만큼을 땡겨와서 쓰더라.