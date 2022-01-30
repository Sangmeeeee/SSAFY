문제 : [이차원 배열과 연산](https://www.acmicpc.net/problem/17140)

알고리즘 종류 : 정렬, 구현

참조 url :

# 1. 알고리즘 설명

R과 C에 따라 연산을 다르게 해준다.

각 라인마다 실행하면 반드시 (key, value) 형식의 자료형이 나오기 때문에 Pair 클래스를 만들어서 각 라인마다 연산 수행 결과를

map에 넣어주고 한 줄의 연산이 모두 끝나면 map에 저장되어있는 Pair를 모두 PriorityQueue에 넣어준다.

PriorityQueue는 value의 오름차순, value가 같다면 key의 오름차순 순으로 정렬되게 한 후

pq에서 poll해서 ary에 넣어준다.

해당 과정에서 반드시 ary의 size는 pq의 2배 사이즈가 될 텐데 R이나 C가 100이 넘어가면 100으로 고정시켜 주고

여기서 주의할 점은 R과 C의 값이 전보다 작아질 수 있기때문에 R과 C의 연산은 항상 연산이 끝난 후의 최대값으로 해준다.

또한 가로 연산은 상관없지만 가로 연산이 끝난 후 세로 연산을 시작할때 

0
3
1

처럼 0으로 시작하는 경우도 있어서 0이라고 for문을 중단하지 않고 continue로 넘어가줬다.

# 2. 새로 배운 내용

(key, value) 형태로 PriorityQueue에 넣기위해선 우선 순위를 정해 줄 필요가 있었다.

우선순위를 정해주기 위해선 Comparable 인터페이스를 구현해줘야 한다.

Pair 인스턴스끼리 비교할때 요구 조건은 value가 낮은 순(오름차순), value가 같다면 key가 낮은 순(오름차순)으로 정렬해 줘야한다.

만약 비교할 Pair 인스턴스의 value값보다 현재 인스턴스의 값이 작다면 현재 인스턴스의 value값이 비교할 인스턴스의 value보다 음수만큼 크다는 뜻으로

음수를 반환해준다. 반대로 현재 인스턴스의 value값이 더 크다면 양수를 반환해준다.

```java
class Pair implements Comparable<Pair>{
    int key, value;
    public Pair(int key, int value){
        this.key = key;
        this.value = value;
    }

    @Override
    public int compareTo(Pair o) {
        if(this.value > o.value){
            return 1;
        }else if(this.value == o.value){
            if(this.key > o.key){
                return 1;
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }
}
```

처음 작성한 코드는 위와 같은 코드였지만 생각해보면 단순히 해당 두 수의 차를 return해주면 자연스럽게 오름차순 정렬이 된다.

```java
class Pair implements Comparable<Pair>{
    int key, value;
    public Pair(int key, int value){
        this.key = key;
        this.value = value;
    }

    @Override
    public int compareTo(Pair o) {
        if(this.value == o.value){
            return this.key - o.key;
        }
        return this.value - o.key;
    }
}
```

만약 여기서 this.key - o.value로 순서를 바꿔버린다 key값을 기준으로 내림차순, key 값이 같다면 value값을 기준으로 오름차순이 된다.