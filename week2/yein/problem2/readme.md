# Info

문제 : [다리를 지나는 트럭](https://programmers.co.kr/learn/courses/30/lessons/42583)

알고리즘 종류 : 스택, 큐

참조 url : 없음

# 알고리즘 설명
<img src = "https://user-images.githubusercontent.com/77979505/152627157-caf9e89b-1918-4545-ba8d-c2bf0c3b113a.jpg" width="80%" height="50%">

1. bridge_truck : deque로 지나가는 트럭을 append하고 popleft 해줄 변수로 선언한다.
2. truck_weights가 empty 상태가 아니면 계속해서 현재 다리에 있는 트럭의 무게와 append할 트럭의 무게를 체크하여 weight가 넘지않도록 append를 해준다.
3. 만약에 weight가 넘는다면 bridge_truck에 0을 append 해준다.
4. 계속해서 bridge_truck이 empty 상태일 때 까지 popleft를 해준다. -> popleft 수 = answer 수  

# 새로 배운 내용