문제 : [회의실 배정] ([url](https://www.acmicpc.net/problem/1931))

알고리즘 종류 : 정렬

참조 url : 

# 1. 알고리즘 설명(로직위주)

## 문제 이해

문제 이해는 어려움 없었음. 

처음에 DP 로 접근할까 생각하다가 곰곰히 생각 해보니 다중조건 정렬로 문제가 풀리겠다 싶어서 다중조건 정렬로 문제를 풀었다.

N개의 시간(시작시간, 종료시간)이 입력으로 주어지고, 최대 회의를 잡을 수 있는 갯수를 출력 하는 문제있다.

## 로직

static class Pair를 int start,int end 를 묶어서 저장 하는 클래스를 만들었다. 이 클래스를  interface Comparable 을 상속 받아서 end 오름차순, start 오름차순으로 다중조건 정렬 했다.

이를 ArrayList 로 add 한 parList 를 sort 한 후, startableTime 이라는 int 변수를 통해서 end 와 start 보다 큰지 비교를 하고 둘다 startableTime 보다 크면 answer++ 을 해준다.

이후 answer 를 출력한다.

# 2. 새로 배운 내용(코드위주)

## 왜 스태틱 클래스, 스태틱 메서드로  만들어 주어야 하는 이유.

```java

public class StaticClassAndMethod {
    static lass Pair{
        int a;
        int b;
        Pair(int a, int b){
            this.a = a;
            this.b = b;
        }
        void print(){
            System.out.println(a+" "+b);
        }
    }
    static void printHello(){
        System.out.println("hello world");
    }
    public static void main(String[] args) {
        Pair p = new Pair(1,2);
        p.print();
        printHello();
    }
}
```

### static 변수, static 메서드, static 클래스

static 은 모두 메모리 공간에 쓰는 것이다. 따라서 객체 생성 없이 호출 가능! 또한 GC 에 의해 삭제 되지 않는다(힙 영역이 아니기 때문.)

static 변수 : 클래스 로딩시 메모리 공간 하나 쓰는 변수. 개별 객체 생성과 무관.

static method : 객체 생성 없이 호출 가능.

배웠었는데 다시 확실시 하고싶어서 써봤다.