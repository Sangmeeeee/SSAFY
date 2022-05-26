# Info

  

문제 : [주차요금](https://programmers.co.kr/learn/courses/30/lessons/92341)

알고리즘 종류 : 

참조 url : 
  

# 알고리즘 설명
`record` [시각, 차량번호, 내역]을 저장하는 vector  
`inout` <차량번호, 입차시간>을 저장하는 map  
`time` <차량번호, 주차시간>을 저장하는 map  
`car_number` 차량번호를 저장하는 set  
`answer` 각 차량의 주차요금을 저장하는 vector


1. `record`의 내역이 "IN"이면 `inout`에 <차량번호, 입차시간>을 insert한다.
    - 이 때, `car_number`에 해당 차량번호가 있는지 확인한다.
    - 차량번호가 없으면 `car_number`에 insert하고 `time`에도 <차량번호, 0>을 insert한다.
2. `record`의 내역이 "OUT"이면 `inout`에서 해당 차량번호의 입차시간을 꺼내서 주차시간을 계산한다.
    - `time[차량번호]`에 계산한 주차시간을 더해준다.
3. 모든 `record`를 확인했으면 23:59를 출차시간으로 해서 `inout`에 남은 차량들의 주차시간을 구한다.
4. `car_number`에 저장된 차량번호 순서대로 주차요금을 구해서 `answer`에 넣는다.
   - `car_number`는 set이기 때문에 오름차순을 디폴트로 정렬이 된다.


# 새로 배운 내용
